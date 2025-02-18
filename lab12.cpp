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

int main() {
    // Example graph (replace with your actual graph data)
    int numVertices = 5;

    // Create an array of pointers to Node to represent adjacency list
    Node* adjList[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr;
    }

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 0);

    // Create a visited array to keep track of visited vertices
    bool visited[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    cout << "DFS Traversal (starting from vertex 0): ";
    DFS(adjList, 0, visited);

    cout << endl;

    return 0;
}