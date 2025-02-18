#include <iostream>

using namespace std;

// Structure to represent a node in the linked list
struct Node {
    int vertex;
    Node* next;
};

// Function to create a new node in the linked list
Node* newNode(int vertex) {
    Node* temp = new Node;
    temp->vertex = vertex;
    temp->next = nullptr;
    return temp;
}

// Function to add an edge to the adjacency list represented by a linked list
void addEdge(Node* adjList[], int source, int destination) {
    Node* newnode = newNode(destination);
    newnode->next = adjList[source]; // Add the new node to the head of the list for source vertex
    adjList[source] = newnode;
}

// Function to initialize the adjacency list
void initializeGraph(Node* adjList[], int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr;
    }
}

// Function to perform DFS traversal of a graph
void DFS(Node* adjList[], int startVertex, bool visited[]) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    // Recur for all the adjacent vertices of the current vertex
    for (Node* neighbor = adjList[startVertex]; neighbor != nullptr; neighbor = neighbor->next) {
        if (!visited[neighbor->vertex]) {
            DFS(adjList, neighbor->vertex, visited);
        }
    }
}

// Function to print the adjacency list
void printGraph(Node* adjList[], int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        Node* current = adjList[i];
        while (current != nullptr) {
            cout << current->vertex << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
}

int main() {
    int numVertices, numEdges;
    
    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Create an array of pointers to Node to represent adjacency list
    Node* adjList[numVertices];
    initializeGraph(adjList, numVertices);

    // Input the edges
    cout << "Enter the edges (source destination): " << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        addEdge(adjList, source, destination);
    }

    // Print the adjacency list
    printGraph(adjList, numVertices);

    // Create a visited array to keep track of visited vertices
    bool visited[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    // Perform DFS traversal starting from vertex 0
    cout << "DFS Traversal (starting from vertex 0): ";
    DFS(adjList, 0, visited);
    cout << endl;

    return 0;
}
