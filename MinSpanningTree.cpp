#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int vertices, edges;
    vector<Edge> edgeList;
};

bool compare(Edge &a, Edge &b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int> &parent) {
    if (parent[v] == v) return v;
    return findParent(parent[v], parent);
}

void kruskalMST(Graph &graph) {
    vector<Edge> result;
    vector<int> parent(graph.vertices);
    for (int i = 0; i < graph.vertices; i++) {
        parent[i] = i;
    }

    sort(graph.edgeList.begin(), graph.edgeList.end(), compare);

    for (Edge edge : graph.edgeList) {
        int sourceParent = findParent(edge.source, parent);
        int destParent = findParent(edge.destination, parent);

        if (sourceParent != destParent) {
            result.push_back(edge);
            parent[sourceParent] = destParent;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge edge : result) {
        cout << edge.source << " -- " << edge.destination << " with weight " << edge.weight << endl;
    }
}

int main() {
    Graph graph;
    graph.vertices = 4;
    graph.edges = 5; 
    graph.edgeList = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    kruskalMST(graph);

    return 0;
}
