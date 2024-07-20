// Write a C program to implement DFS graph traversal algorithm.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure to represent an adjacency list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Function to create a new adjacency list node
AdjListNode* createNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists. Size of array will be numVertices
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));

    // Initialize each adjacency list as empty by making head NULL
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src
    AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// DFS utility function
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    // Mark the current node as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    AdjListNode* temp = graph->array[vertex].head;
    while (temp) {
        int connectedVertex = temp->dest;
        if (!visited[connectedVertex]) {
            DFSUtil(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal. It uses recursive DFSUtil()
void DFS(Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int visited[MAX_VERTICES] = {0};

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, startVertex, visited);
}

// Main function
void main() {
    // Create a graph given in the above diagram
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);
}
