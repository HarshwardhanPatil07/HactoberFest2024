#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Structure to represent a graph using an adjacency matrix
struct GraphMatrix {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Edge {
    int start;
    int end;
    int weight;
};


// Structure to represent a graph using an adjacency list
struct ListNode {
    int data;
    int weight;
    struct ListNode* next;
};

struct GraphList {
    int vertices;
    struct ListNode* adjList[MAX_VERTICES];
};

// Function prototypes for adjacency matrix
struct GraphMatrix* createGraphMatrix(int vertices);
void addEdgeMatrix(struct GraphMatrix* graph, int start, int end, int weight);
void displayMatrix(struct GraphMatrix* graph);

// Function prototypes for adjacency list
struct GraphList* createGraphList(int vertices);
void addEdgeList(struct GraphList* graph, int start, int end, int weight);
void displayList(struct GraphList* graph);

// Prim's algorithm
void primMatrix(struct GraphMatrix* graph);
void primList(struct GraphList* graph);

// Kruskal's algorithm
void kruskalMatrix(struct GraphMatrix* graph);
void kruskalList(struct GraphList* graph);

// Common functions
void insertEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList);
void deleteEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList);
void displayGraph(struct GraphMatrix* graphMatrix, struct GraphList* graphList);

int main() {
    int choiceGraph, choiceAlgorithm;

    struct GraphMatrix* graphMatrix = NULL;
    struct GraphList* graphList = NULL;

    while (1) {
        printf("\nChoose the type of graph representation:\n");
        printf("1. Adjacency Matrix\n");
        printf("2. Adjacency List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choiceGraph);

        if (choiceGraph == 3) {
            exit(0);
        }

        printf("\nChoose the algorithm:\n");
        printf("1. Prim's Algorithm\n");
        printf("2. Kruskal's Algorithm\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choiceAlgorithm);

        if (choiceAlgorithm == 3) {
            continue;
        }

        switch (choiceGraph) {
            case 1: // Adjacency Matrix
                if (graphMatrix == NULL) {
                    printf("Enter the number of vertices: ");
                    int vertices;
                    scanf("%d", &vertices);
                    graphMatrix = createGraphMatrix(vertices);
                }

                switch (choiceAlgorithm) {
                    case 1: // Prim's Algorithm with Matrix
                        primMatrix(graphMatrix);
                        break;
                    case 2: // Kruskal's Algorithm with Matrix
                        kruskalMatrix(graphMatrix);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 2: // Adjacency List
                if (graphList == NULL) {
                    printf("Enter the number of vertices: ");
                    int vertices;
                    scanf("%d", &vertices);
                    graphList = createGraphList(vertices);
                }

                switch (choiceAlgorithm) {
                    case 1: // Prim's Algorithm with List
                        primList(graphList);
                        break;
                    case 2: // Kruskal's Algorithm with List
                        kruskalList(graphList);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Display Graph\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice for operation: ");
        int choiceOperation;
        scanf("%d", &choiceOperation);

        switch (choiceOperation) {
            case 1:
                insertEdge(graphMatrix, graphList);
                break;
            case 2:
                deleteEdge(graphMatrix, graphList);
                break;
            case 3:
                displayGraph(graphMatrix, graphList);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Functions for adjacency matrix
struct GraphMatrix* createGraphMatrix(int vertices) {
    struct GraphMatrix* graph = (struct GraphMatrix*)malloc(sizeof(struct GraphMatrix));
    graph->vertices = vertices;

    // Initialize adjacency matrix with INF values
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j] = INF;
        }
    }

    return graph;
}

void addEdgeMatrix(struct GraphMatrix* graph, int start, int end, int weight) {
    graph->adjMatrix[start][end] = weight;
    graph->adjMatrix[end][start] = weight;
}

void displayMatrix(struct GraphMatrix* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        for (int j = 0; j < graph->vertices; ++j) {
            if (graph->adjMatrix[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Functions for adjacency list
struct GraphList* createGraphList(int vertices) {
    struct GraphList* graph = (struct GraphList*)malloc(sizeof(struct GraphList));
    graph->vertices = vertices;

    // Initialize adjacency list with NULL values
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdgeList(struct GraphList* graph, int start, int end, int weight) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = end;
    newNode->weight = weight;
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;

    // For undirected graphs, you may want to add the reverse edge as well
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = start;
    newNode->weight = weight;
    newNode->next = graph->adjList[end];
    graph->adjList[end] = newNode;
}

void displayList(struct GraphList* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d: ", i);
        struct ListNode* current = graph->adjList[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->data, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

// Prim's algorithm with adjacency matrix
void primMatrix(struct GraphMatrix* graph) {
    int parent[MAX_VERTICES]; // To store the parent of each vertex in MST
    int key[MAX_VERTICES];    // To store the key value of each vertex
    int inMST[MAX_VERTICES];  // To track whether a vertex is in MST or not

    // Initialize key values and inMST array
    for (int i = 0; i < graph->vertices; ++i) {
        key[i] = INF;
        inMST[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is the root of MST

    for (int count = 0; count < graph->vertices - 1; ++count) {
        // Find the vertex with the minimum key value
        int minKey = INF, minIndex;
        for (int v = 0; v < graph->vertices; ++v) {
            if (inMST[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Include the found vertex in MST
        inMST[minIndex] = 1;

        // Update key values of adjacent vertices
        for (int v = 0; v < graph->vertices; ++v) {
            if (graph->adjMatrix[minIndex][v] != INF && inMST[v] == 0 &&
                graph->adjMatrix[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph->adjMatrix[minIndex][v];
            }
        }
    }

    // Display the MST
    printf("Edges in MST (Prim's Algorithm with Adjacency Matrix):\n");
    for (int i = 1; i < graph->vertices; ++i) {
        printf("(%d, %d) - Weight: %d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
    }
}

// Prim's algorithm with adjacency list
void primList(struct GraphList* graph) {
    int parent[MAX_VERTICES]; // To store the parent of each vertex in MST
    int key[MAX_VERTICES];    // To store the key value of each vertex
    int inMST[MAX_VERTICES];  // To track whether a vertex is in MST or not

    // Initialize key values and inMST array
    for (int i = 0; i < graph->vertices; ++i) {
        key[i] = INF;
        inMST[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1; // First node is the root of MST

    for (int count = 0; count < graph->vertices - 1; ++count) {
        // Find the vertex with the minimum key value
        int minKey = INF, minIndex;
        for (int v = 0; v < graph->vertices; ++v) {
            if (inMST[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Include the found vertex in MST
        inMST[minIndex] = 1;

        // Update key values of adjacent vertices
        struct ListNode* current = graph->adjList[minIndex];
        while (current != NULL) {
            int v = current->data;
            int weight = current->weight;

            if (inMST[v] == 0 && weight < key[v]) {
                parent[v] = minIndex;
                key[v] = weight;
            }

            current = current->next;
        }
    }

    // Display the MST
    printf("Edges in MST (Prim's Algorithm with Adjacency List):\n");
    for (int i = 1; i < graph->vertices; ++i) {
        printf("(%d, %d) - Weight: %d\n", parent[i], i, key[i]);
    }
}

// Function prototypes for kruskalMatrix and kruskalList
int compareEdges(const void* a, const void* b);
int findSet(int parent[], int i);
void unionSets(int parent[], int x, int y);

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the set of an element in the disjoint set
int findSet(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return findSet(parent, parent[i]);
}

// Function to perform union of two sets in the disjoint set
void unionSets(int parent[], int x, int y) {
    int xSet = findSet(parent, x);
    int ySet = findSet(parent, y);

    parent[xSet] = ySet;
}


// Kruskal's algorithm with adjacency matrix
void kruskalMatrix(struct GraphMatrix* graph) {
    int parent[MAX_VERTICES]; // To store the parent of each vertex in a set
    struct Edge result[MAX_VERTICES - 1]; // To store the edges of the minimum spanning tree
    int edgeCount = 0; // Counter for selected edges

    // Initialize parent array, all vertices are in different sets initially
    for (int i = 0; i < graph->vertices; ++i) {
        parent[i] = -1;
    }

    // Create a sorted array of all edges in the graph
    struct Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeIndex = 0;
    for (int i = 0; i < graph->vertices; ++i) {
        for (int j = i + 1; j < graph->vertices; ++j) {
            if (graph->adjMatrix[i][j] != INF) {
                edges[edgeIndex].start = i;
                edges[edgeIndex].end = j;
                edges[edgeIndex].weight = graph->adjMatrix[i][j];
                ++edgeIndex;
            }
        }
    }

    // Sort the edges in non-decreasing order of weight
    qsort(edges, edgeIndex, sizeof(struct Edge), compareEdges);

    // Apply Kruskal's algorithm
    for (int i = 0; i < edgeIndex && edgeCount < graph->vertices - 1; ++i) {
        int start = edges[i].start;
        int end = edges[i].end;
        int weight = edges[i].weight;

        // Check if including this edge forms a cycle or not
        if (findSet(parent, start) != findSet(parent, end)) {
            result[edgeCount].start = start;
            result[edgeCount].end = end;
            result[edgeCount].weight = weight;
            ++edgeCount;

            // Perform union of the sets of start and end vertices
            unionSets(parent, start, end);
        }
    }

    // Display the minimum spanning tree
    printf("Edges in MST (Kruskal's Algorithm with Adjacency Matrix):\n");
    for (int i = 0; i < graph->vertices - 1; ++i) {
        printf("(%d, %d) - Weight: %d\n", result[i].start, result[i].end, result[i].weight);
    }
}

// Kruskal's algorithm with adjacency list
void kruskalList(struct GraphList* graph) {
    int parent[MAX_VERTICES]; // To store the parent of each vertex in a set
    struct Edge result[MAX_VERTICES - 1]; // To store the edges of the minimum spanning tree
    int edgeCount = 0; // Counter for selected edges

    // Initialize parent array, all vertices are in different sets initially
    for (int i = 0; i < graph->vertices; ++i) {
        parent[i] = -1;
    }

    // Create a sorted array of all edges in the graph
    struct Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeIndex = 0;
    for (int i = 0; i < graph->vertices; ++i) {
        struct ListNode* current = graph->adjList[i];
        while (current != NULL) {
            edges[edgeIndex].start = i;
            edges[edgeIndex].end = current->data;
            edges[edgeIndex].weight = current->weight;
            ++edgeIndex;
            current = current->next;
        }
    }

    // Sort the edges in non-decreasing order of weight
    qsort(edges, edgeIndex, sizeof(struct Edge), compareEdges);

    // Apply Kruskal's algorithm
    for (int i = 0; i < edgeIndex && edgeCount < graph->vertices - 1; ++i) {
        int start = edges[i].start;
        int end = edges[i].end;
        int weight = edges[i].weight;

        // Check if including this edge forms a cycle or not
        if (findSet(parent, start) != findSet(parent, end)) {
            result[edgeCount].start = start;
            result[edgeCount].end = end;
            result[edgeCount].weight = weight;
            ++edgeCount;

            // Perform union of the sets of start and end vertices
            unionSets(parent, start, end);
        }
    }

    // Display the minimum spanning tree
    printf("Edges in MST (Kruskal's Algorithm with Adjacency List):\n");
    for (int i = 0; i < graph->vertices - 1; ++i) {
        printf("(%d, %d) - Weight: %d\n", result[i].start, result[i].end, result[i].weight);
    }
}

// Common functions
void insertEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList) {
    int start, end, weight;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);
    printf("Enter the weight of the edge: ");
    scanf("%d", &weight);

    if (graphMatrix != NULL) {
        addEdgeMatrix(graphMatrix, start, end, weight);
    }

    if (graphList != NULL) {
        addEdgeList(graphList, start, end, weight);
    }
}

void deleteEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList) {
    int start, end;
    printf("Enter the starting vertex of the edge to delete: ");
    scanf("%d", &start);
    printf("Enter the ending vertex of the edge to delete: ");
    scanf("%d", &end);

    // Delete edge from adjacency matrix
    graphMatrix->adjMatrix[start][end] = INF;
    graphMatrix->adjMatrix[end][start] = INF;

    // Delete edge from adjacency list
    struct ListNode* current = graphList->adjList[start];
    struct ListNode* prev = NULL;

    while (current != NULL && current->data != end) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            graphList->adjList[start] = current->next;
        }

        free(current);
    }

    // For undirected graphs, remove the reverse edge as well
    current = graphList->adjList[end];
    prev = NULL;

    while (current != NULL && current->data != start) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            graphList->adjList[end] = current->next;
        }

        free(current);
    }

    printf("Edge (%d, %d) deleted from both adjacency matrix and adjacency list.\n", start, end);
}


void displayGraph(struct GraphMatrix* graphMatrix, struct GraphList* graphList) {
    if (graphMatrix != NULL) {
        displayMatrix(graphMatrix);
    }

    if (graphList != NULL) {
        displayList(graphList);
    }
}