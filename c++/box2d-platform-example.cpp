#include <iostream>
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "sre/Texture.hpp"
#include "sre/Inspector.hpp"
#include "glm/gtc/random.hpp"
#include "glm/ext.hpp"
#include "Box2D/Box2D.h"

using namespace sre;
using namespace std;

// Captures debug information from Box2D as lines (polygon fill and color is discarded)
class Box2DDebugDraw : public b2Draw{
public:
    Box2DDebugDraw(){
        SetFlags( b2Draw::e_shapeBit );
    }
    void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override {
        for (int i=0;i<vertexCount;i++){
            lines.push_back({vertices[i].x,vertices[i].y,0});
            lines.push_back({vertices[(i+1)%vertexCount].x,vertices[(i+1)%vertexCount].y,0});
        }
    }

    void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override {
        DrawPolygon(vertices, vertexCount, color);
    }

    void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) override {
        glm::vec3 c {center.x,center.y,0};
        for (int i=0;i<16;i++){
            float v = i*glm::two_pi<float>()/16;
            float v1 = (i+1)*glm::two_pi<float>()/16;
            lines.push_back(c+glm::vec3{sin(v ) , cos(v ) , 0} * radius);
            lines.push_back(c+glm::vec3{sin(v1) , cos(v1) , 0} * radius);
        }
    }

    void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) override {
        DrawCircle(center, radius, color);
    }

    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override {
        lines.push_back({p1.x,p1.y,0});
        lines.push_back({p2.x,p2.y,0});
    }

    void DrawTransform(const b2Transform &xf) override {
    }

    void DrawPoint(const b2Vec2 &p, float32 size, const b2Color &color) override {}

    void clear(){
        lines.clear();
    }

    const vector<glm::vec3>& getLines(){
        return lines;
    }
private:
    vector<glm::vec3> lines;
};

class Box2DPlatform {
public:
    Box2DPlatform()
    :m_world({0.0f,-98.0f})
    {
        m_world.SetDebugDraw(&debugDraw);                                           // enable debug draw (line drawing on colliders)

        glm::ivec2 windowSize(800,600);
        r.setWindowSize(windowSize);
        r.init().withSdlInitFlags(SDL_INIT_EVERYTHING)
                .withSdlWindowFlags(SDL_WINDOW_OPENGL)
                .withVSync(false);


        r.setWindowTitle("Box2D example. Use arrow-key + space to control character");

        camera.setWindowCoordinates();

        spawnBox(b2_staticBody, windowSize.x/2, 20, 200, 10);
        spawnBox(b2_staticBody, windowSize.x/2, 400, 200, 10);

        platformUpDown = spawnBox(b2_kinematicBody, 650, 20, 50, 10);
        platformLeftRight = spawnBox(b2_kinematicBody, 150, 200, 50, 10);

        player = spawnBox(b2_dynamicBody, windowSize.x/2, 30, 10, 10);

        r.frameUpdate = [&](float deltaTime){                                       // Update physics simulation before rendering
            time += deltaTime;
            physicsUpdate();
        };
        r.frameRender = [&](){
            render();
        };

        r.keyEvent = [&](SDL_Event & e){
            onKey(e);
        };

        r.startEventLoop();
    }

    void physicsUpdate(){
        updateMovingPlatforms();

        float fixedDeltaTime = 0.016f;                                          // Run physics simulation
        int32 velocityIterations = 8;                                           // how strongly to correct velocity
        int32 positionIterations = 3;                                           // how strongly to correct position
        m_world.Step(fixedDeltaTime,velocityIterations,positionIterations);
    }

    void updateMovingPlatforms() const {
        b2Body* upDown = platformUpDown->GetBody();
        float moveFrom = 20;
        float moveTo = 400;
        if (upDown->GetType() == b2_kinematicBody) {
            upDown->SetAwake(true);
            if (upDown->GetLinearVelocity().y <= 0 && upDown->GetPosition().y <= moveFrom) {
                b2Vec2 velocity(0, 100);
                upDown->SetLinearVelocity(velocity);
            } else if (upDown->GetLinearVelocity().y >= 0 && upDown->GetPosition().y >= moveTo) {
                b2Vec2 velocity(0, -100);
                upDown->SetLinearVelocity(velocity);
            }
        } else if (upDown->GetType() == b2_staticBody) {
            float yPos = (sin(time) * 0.5f + 0.5f) * (moveTo - moveFrom) + moveFrom;
            float xPos = upDown->GetPosition().x;
            upDown->SetTransform(b2Vec2(xPos,yPos),0);
        }

        b2Body * leftRight = platformLeftRight->GetBody();
        float left = 50;
        float right = 250;
        if (leftRight->GetType() == b2_kinematicBody) {
            if (leftRight->GetLinearVelocity().x == 0 || (leftRight->GetLinearVelocity().x <= 0 && leftRight->GetPosition().x <= left)) {
                b2Vec2 velocity(100,0);
                leftRight->SetLinearVelocity(velocity);
            } else if (leftRight->GetLinearVelocity().x >= 0 && leftRight->GetPosition().x >= right) {
                b2Vec2 velocity(-100,0);
                leftRight->SetLinearVelocity(velocity);
            }
        } else if (leftRight->GetType() == b2_staticBody){
            float xPos = (sin(time) * 0.5f + 0.5f) * (right - left) + left;
            float yPos = leftRight->GetPosition().y;
            leftRight->SetTransform(b2Vec2(xPos,yPos),0);
        }
    }

    void onKey(SDL_Event &event) {
        bool down = event.type == SDL_KEYDOWN;
        if (event.key.keysym.sym == SDLK_LEFT){
            left = down;
        }
        if (event.key.keysym.sym == SDLK_RIGHT){
            right = down;
        }
        b2Vec2 v{0, 0};
        if (left){
            v.x = -100;
        }
        if (right){
            v.x += 100;
        }
        b2Body* body = player->GetBody();
        body->SetAwake(true);
        body->SetLinearVelocity(v);
        if (down && (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) ){
            b2Vec2 impulse{0, 40000};
            body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
        }
    }

    void render(){
        auto renderPass = RenderPass::create()
                .withCamera(camera)
                .withClearColor(true,{.92f, .92f, .92f, 1.0f})
                .build();

        // debug draw
        m_world.DrawDebugData();
        renderPass.drawLines(debugDraw.getLines(),{0,0,0,1});
        debugDraw.clear();
    }

    b2Fixture* spawnBox(b2BodyType type, int posX, int posY, float sizeX, float sizeY, float elasticity = 0.8) {
        b2BodyDef myBodyDef;
        myBodyDef.type = type;
        myBodyDef.position.Set(posX,posY);      //set the starting position
        myBodyDef.angle = 0;                        //set the starting angle
        auto dynBody = m_world.CreateBody(&myBodyDef);

        b2PolygonShape boxShape;
        boxShape.SetAsBox(sizeX, sizeY);

        b2FixtureDef boxFixtureDef;
        boxFixtureDef.shape = &boxShape;
        boxFixtureDef.restitution = elasticity;   // elasticity [0;1]
        boxFixtureDef.density = 1;         // weight
        auto res = dynBody->CreateFixture(&boxFixtureDef);
        return res;
    }

    b2Fixture* spawnCircle(b2BodyType type, float posX, float posY, float radius = 1) {
        b2BodyDef myBodyDef;
        myBodyDef.type = type;
        myBodyDef.position.Set(posX,posY);      //set the starting position
        myBodyDef.angle = 0;                        //set the starting angle
        auto dynBody = m_world.CreateBody(&myBodyDef);

        b2CircleShape circleShape;
        circleShape.m_radius = radius; //radius

        b2FixtureDef boxFixtureDef;
        boxFixtureDef.shape = &circleShape;
        boxFixtureDef.restitution = 0.8;   // elasticity [0;1]
        boxFixtureDef.density = 1;         // weight
        auto res = dynBody->CreateFixture(&boxFixtureDef);

        return res;
    }
private:
    b2World m_world;
    SDLRenderer r;
    Camera camera;
    Box2DDebugDraw debugDraw;
    float time = 0;
    b2Fixture* player;
    b2Fixture* platformUpDown;
    b2Fixture* platformLeftRight;
    bool left;
    bool right;
};

int main() {
    std::cout << "https://github.com/mortennobel/SimpleRenderEngineProject" << std::endl;
    new Box2DPlatform();

    return 0;
}
