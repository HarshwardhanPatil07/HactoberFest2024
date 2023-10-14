#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph using an adjacency matrix
struct GraphMatrix {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Structure to represent a graph using an adjacency list
struct ListNode {
    int data;
    struct ListNode* next;
};

struct GraphList {
    int vertices;
    struct ListNode* adjList[MAX_VERTICES];
};

// Function prototypes for adjacency matrix
struct GraphMatrix* createGraphMatrix(int vertices);
void addEdgeMatrix(struct GraphMatrix* graph, int start, int end);
void deleteEdgeMatrix(struct GraphMatrix* graph, int start, int end);
void dfsMatrix(struct GraphMatrix* graph, int start, int visited[]);
void bfsMatrix(struct GraphMatrix* graph, int start);
void displayMatrix(struct GraphMatrix* graph);

// Function prototypes for adjacency list
struct GraphList* createGraphList(int vertices);
void addEdgeList(struct GraphList* graph, int start, int end);
void deleteEdgeList(struct GraphList* graph, int start, int end);
void dfsList(struct GraphList* graph, int start, int visited[]);
void bfsList(struct GraphList* graph, int start);
void displayList(struct GraphList* graph);

// Common function prototypes
void insertEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList);
void displayGraph(struct GraphMatrix* graphMatrix, struct GraphList* graphList);

int main() {
    int choiceTraversal, choiceGraph;

    struct GraphMatrix* graphMatrix = NULL;
    struct GraphList* graphList = NULL;

    while (1) {
        printf("\nChoose the traversal algorithm:\n");
        printf("1. Depth-First Search (DFS)\n");
        printf("2. Breadth-First Search (BFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choiceTraversal);

        if (choiceTraversal == 3) {
            exit(0);
        }

        printf("\nChoose the type of graph representation:\n");
        printf("1. Adjacency Matrix\n");
        printf("2. Adjacency List\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choiceGraph);

        if (choiceGraph == 3) {
            continue;
        }

        switch (choiceTraversal) {
            case 1: // DFS
                switch (choiceGraph) {
                    case 1: // Adjacency Matrix
                        if (graphMatrix == NULL) {
                            printf("Enter the number of vertices: ");
                            int vertices;
                            scanf("%d", &vertices);
                            graphMatrix = createGraphMatrix(vertices);
                        }

                        printf("DFS using Adjacency Matrix:\n");
                        int visitedMatrix[MAX_VERTICES] = {0};
                        dfsMatrix(graphMatrix, 0, visitedMatrix);

                        break;

                    case 2: // Adjacency List
                        if (graphList == NULL) {
                            printf("Enter the number of vertices: ");
                            int vertices;
                            scanf("%d", &vertices);
                            graphList = createGraphList(vertices);
                        }

                        printf("DFS using Adjacency List:\n");
                        int visitedList[MAX_VERTICES] = {0};
                        dfsList(graphList, 0, visitedList);

                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 2: // BFS
                switch (choiceGraph) {
                    case 1: // Adjacency Matrix
                        if (graphMatrix == NULL) {
                            printf("Enter the number of vertices: ");
                            int vertices;
                            scanf("%d", &vertices);
                            graphMatrix = createGraphMatrix(vertices);
                        }

                        printf("BFS using Adjacency Matrix:\n");
                        bfsMatrix(graphMatrix, 0);

                        break;

                    case 2: // Adjacency List
                        if (graphList == NULL) {
                            printf("Enter the number of vertices: ");
                            int vertices;
                            scanf("%d", &vertices);
                            graphList = createGraphList(vertices);
                        }

                        printf("BFS using Adjacency List:\n");
                        bfsList(graphList, 0);

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
                if (choiceGraph == 1) {
                    deleteEdgeMatrix(graphMatrix, 0, 0);
                } else if (choiceGraph == 2) {
                    deleteEdgeList(graphList, 0, 0);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 3:
                if (choiceGraph == 1) {
                    displayMatrix(graphMatrix);
                } else if (choiceGraph == 2) {
                    displayList(graphList);
                } else {
                    printf("Invalid choice.\n");
                }
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

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdgeMatrix(struct GraphMatrix* graph, int start, int end) {
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void deleteEdgeMatrix(struct GraphMatrix* graph, int start, int end) {
    graph->adjMatrix[start][end] = 0;
    graph->adjMatrix[end][start] = 0;
}

void dfsMatrix(struct GraphMatrix* graph, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->adjMatrix[start][i] == 1 && !visited[i]) {
            dfsMatrix(graph, i, visited);
        }
    }
}

void bfsMatrix(struct GraphMatrix* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < graph->vertices; ++i) {
            if (graph->adjMatrix[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void displayMatrix(struct GraphMatrix* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        for (int j = 0; j < graph->vertices; ++j) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Functions for adjacency list
struct GraphList* createGraphList(int vertices) {
    struct GraphList* graph = (struct GraphList*)malloc(sizeof(struct GraphList));
    graph->vertices = vertices;

    // Initialize adjacency list
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdgeList(struct GraphList* graph, int start, int end) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = end;
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;

    // For undirected graphs, you may want to add the reverse edge as well
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = start;
    newNode->next = graph->adjList[end];
    graph->adjList[end] = newNode;
}

void dfsList(struct GraphList* graph, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    struct ListNode* current = graph->adjList[start];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            dfsList(graph, neighbor, visited);
        }
        current = current->next;
    }
}

void bfsList(struct GraphList* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct ListNode* current = graph->adjList[node];
        while (current != NULL) {
            int neighbor = current->data;
            if (!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = 1;
            }
            current = current->next;
        }
    }
}

void displayList(struct GraphList* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d: ", i);
        struct ListNode* current = graph->adjList[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void insertEdge(struct GraphMatrix* graphMatrix, struct GraphList* graphList) {
    int start, end;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);

    if (graphMatrix != NULL) {
        addEdgeMatrix(graphMatrix, start, end);
    }

    if (graphList != NULL) {
        addEdgeList(graphList, start, end);
    }
}

void deleteEdgeList(struct GraphList* graph, int start, int end) {
    // Find and remove the edge from the adjacency list
    struct ListNode* current = graph->adjList[start];
    struct ListNode* prev = NULL;

    while (current != NULL && current->data != end) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            graph->adjList[start] = current->next;
        }

        free(current);
    }

    // For undirected graphs, you may also want to remove the reverse edge
    current = graph->adjList[end];
    prev = NULL;

    while (current != NULL && current->data != start) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            graph->adjList[end] = current->next;
        }

        free(current);
    }
}

void displayGraph(struct GraphMatrix* graphMatrix, struct GraphList* graphList) {
    if (graphMatrix != NULL) {
        displayMatrix(graphMatrix);
    }

    if (graphList != NULL) {
        displayList(graphList);
    }
}
