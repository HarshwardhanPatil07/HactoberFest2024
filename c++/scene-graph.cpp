#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "sre/Texture.hpp"
#include "sre/Renderer.hpp"
#include "sre/Material.hpp"
#include "sre/SDLRenderer.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>


using namespace sre;

class Node;

std::shared_ptr<Node> cameraNode;

class Node : public std::enable_shared_from_this<Node> {
public:
    Node() {}

    Node(Node *parent) : parent(parent) {}

    glm::vec3 position = glm::vec3(0,0,0);
    glm::vec3 rotationEuler = glm::vec3(0,0,0);
    glm::vec3 scale = glm::vec3(1,1,1);

    glm::mat4 localToWorld(){
        // compute trs
        auto rotationEulerRadian = glm::radians(rotationEuler);
        auto res = glm::translate(position)
                   * glm::eulerAngleXYZ(rotationEulerRadian.x,rotationEulerRadian.y,rotationEulerRadian.z)
                   * glm::scale(scale);
        if (parent){
            res = parent->localToWorld() * res;
        }
        return res;
    }

    std::vector<std::shared_ptr<Node>> children;
    Node* parent = nullptr;

    void gui(int level = 0){
        ImGui::PushID(this);
        ImGui::Indent(level*20);

        if (ImGui::CollapsingHeader(this == cameraNode.get()?"Camera": "Node")){
            ImGui::DragFloat3("Local Position",&position.x);
            ImGui::DragFloat3("Local Rotation",&rotationEuler.x);
            ImGui::DragFloat3("Local Scale",&scale.x);
            auto globalPos = localToWorld() * glm::vec4(0,0,0,1); // transform 0,0,0 (pivot point) from local coordinate frame to global coordinate frame
            bool changed = ImGui::DragFloat3("Global Position",&globalPos.x);
            if (changed){
                if (parent){
                    position = glm::inverse(parent->localToWorld()) * globalPos;
                }
                else {
                    position = globalPos;
                }
            }
            if (ImGui::Button("Add child")){
                children.push_back(std::make_shared<Node>(this));
            }
            if (ImGui::Button("Make camera")){
                cameraNode = this->shared_from_this();
            }
            for (auto & n : children){
                n->gui(level+1);
            }
        }
        ImGui::Unindent(level*20);
        ImGui::PopID();
    }
};

class SceneGraphExample {
public:
    SceneGraphExample(){
        r.init();

        camera.setPerspectiveProjection(60,0.1,100);

        material = Shader::getStandardBlinnPhong()->createMaterial();
        material->setColor({1.0f,1.0f,1.0f,1.0f});
        material->setSpecularity({0.5,0.5,0.5,20.0f});

        mesh = Mesh::create().withCube().build();
        worldLights.setAmbientLight({0.5,0.5,0.5});
        worldLights.addLight(Light::create().withPointLight({0, 3,0}).withColor({1,0,0}).withRange(20).build());
        worldLights.addLight(Light::create().withPointLight({3, 0,0}).withColor({0,1,0}).withRange(20).build());
        worldLights.addLight(Light::create().withPointLight({0,-3,0}).withColor({0,0,1}).withRange(20).build());
        worldLights.addLight(Light::create().withPointLight({-3,0,0}).withColor({1,1,1}).withRange(20).build());

        root.children.push_back(std::make_shared<Node>(nullptr));
        root.children.push_back(std::make_shared<Node>(nullptr));

        cameraNode = root.children[0];
        cameraNode->position = {0,0,30};

        r.frameRender = [&](){
            auto localToWorld = cameraNode->localToWorld();
            camera.setViewTransform(glm::inverse(localToWorld));
            render();
        };

        r.startEventLoop();
    }

    void render(std::shared_ptr<Node>& node, RenderPass& rp){
        rp.draw(mesh, node->localToWorld(), material);
        // draw children
        for (auto & n : node->children){
            render(n, rp);
        }
    }

    void render(){
        auto renderPass = RenderPass::create()
                .withCamera(camera)
                .withWorldLights(&worldLights)
                .withClearColor(true, {1, 0, 0, 1})
                .build();

        for (auto & n : root.children){
            render(n, renderPass);
        }

        // draw gui
        ImGui::Begin("SceneGraph");
        if (ImGui::Button("Add object")){
            root.children.push_back(std::make_shared<Node>(nullptr));
        }
        for (auto & n : root.children){
            n->gui();
        }
        ImGui::End();

        i++;
    }
private:
    SDLRenderer r;
    Camera camera;
    WorldLights worldLights;
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;
    Node root;
    int i=0;
};

int main() {
    new SceneGraphExample();
    return 0;
}
