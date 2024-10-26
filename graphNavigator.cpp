#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    float f, g, h; // f = g + h
    Node* parent;

    Node(int x, int y) : x(x), y(y), f(0), g(0), h(0), parent(nullptr) {}
    
    // Overload < operator for priority queue
    bool operator>(const Node& other) const {
        return f > other.f; // Min-heap based on f cost
    }
};

// Heuristic function (Euclidean distance)
float heuristic(Node* a, Node* b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

// A* search algorithm
vector<Node*> astar(Node* start, Node* goal, const vector<vector<int>>& grid) {
    priority_queue<Node*, vector<Node*>, greater<Node*>> openSet;
    unordered_map<int, Node*> allNodes; // To keep track of all created nodes
    vector<Node*> path;

    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    openSet.push(start);
    allNodes[start->x * grid[0].size() + start->y] = start;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Four possible directions

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        // Check if we've reached the goal
        if (current->x == goal->x && current->y == goal->y) {
            // Trace back the path
            while (current) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end()); // Reverse the path
            return path;
        }

        // Explore neighbors
        for (auto& dir : directions) {
            int newX = current->x + dir.first;
            int newY = current->y + dir.second;

            // Check boundaries
            if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == 1) {
                continue; // Skip if out of bounds or obstacle
            }

            Node* neighbor = new Node(newX, newY);
            neighbor->g = current->g + 1; // Cost from start to neighbor
            neighbor->h = heuristic(neighbor, goal);
            neighbor->f = neighbor->g + neighbor->h;
            neighbor->parent = current;

            // Check if this path to neighbor is better
            if (allNodes.find(newX * grid[0].size() + newY) == allNodes.end() || neighbor->g < allNodes[newX * grid[0].size() + newY]->g) {
                openSet.push(neighbor);
                allNodes[newX * grid[0].size() + newY] = neighbor; // Add neighbor to allNodes
            }
        }
    }

    return path; // Return empty path if no solution found
}

int main() {
    // Define a grid (0: free space, 1: obstacle)
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Node* start = new Node(0, 0); // Start position
    Node* goal = new Node(4, 4);   // Goal position

    vector<Node*> path = astar(start, goal, grid);

    if (!path.empty()) {
        cout << "Path found: " << endl;
        for (auto node : path) {
            cout << "(" << node->x << ", " << node->y << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    // Clean up allocated memory
    for (auto node : path) {
        delete node; // Deleting nodes in the path
    }
    delete start;
    delete goal;

    return 0;
}
