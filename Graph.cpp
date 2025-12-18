#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h"

using namespace std;

// --- CLASS DEFINITION ---
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool directed = false);

    // Core functionality
    void addEdge(int u, int v, T weight = T());
    int getNumVertices() const;
    void printGraph() const;
    vector<pair<int, T>> getNeighbors(int vertex) const;

    // Traversal (DFT)
    void DFT(int start, const vector<Event>& events) const;
    void DFTRecursive(int v, vector<bool>& visited, const vector<Event>& events) const;

    // Search (DFS)
    bool DFS(const string& eventName, const vector<Event>& events, int start = 0) const;
    bool DFSRecursive(int v, const string& name, vector<bool>& visited, const vector<Event>& events) const;

private:
    int V; // Number of vertices
    bool directed; 
    vector<LinkedBag<pair<int, T>>> adjList; 
};

// --- IMPLEMENTATIONS ---

// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {
    if (u < 0 || u >= V || v < 0 || v >= V) return;
    if (u == v) return;

    adjList[u].append({v, weight});
    if (!directed) {
        adjList[v].append({u, weight});
    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const {
    return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        auto neighbors = adjList[i].toVector();
        for (const auto& n : neighbors) {
            cout << "(" << n.first << ", " << n.second << ") ";
        }
        cout << endl;
    }
}

// Get neighbors of a vertex
template <typename T>
vector<pair<int, T>> Graph<T>::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= V) return {};
    return adjList[vertex].toVector();
}

// DFT Traversal
template <typename T>
void Graph<T>::DFT(int start, const vector<Event>& events) const {
    if (start < 0 || start >= V) return;
    vector<bool> visited(V, false);
    DFTRecursive(start, visited, events);
    cout << endl;
}

// Utility function for DFT (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, vector<bool>& visited, const vector<Event>& events) const {
    visited[v] = true;
    // Prints the event info using the Event class overloaded << operator
    cout << events[v] << " | "; 

    auto neighbors = adjList[v].toVector();
    for (const auto& n : neighbors) {
        if (!visited[n.first]) {
            DFTRecursive(n.first, visited, events);
        }
    }
}

// DFS Search
template <typename T>
bool Graph<T>::DFS(const string& eventName, const vector<Event>& events, int start) const {
    if (start < 0 || start >= V) return false;
    vector<bool> visited(V, false);
    return DFSRecursive(start, eventName, visited, events);
}

// Utility function for DFS (Recursive)
template <typename T>
bool Graph<T>::DFSRecursive(int v, const string& name, vector<bool>& visited, const vector<Event>& events) const {
    visited[v] = true;

    // Check if current vertex is the target
    if (events[v].getName() == name) {
        return true;
    }

    // Recur for neighbors
    auto neighbors = adjList[v].toVector();
    for (const auto& n : neighbors) {
        if (!visited[n.first]) {
            if (DFSRecursive(n.first, name, visited, events)) {
                return true; 
            }
        }
    }
    return false;
}

#endif