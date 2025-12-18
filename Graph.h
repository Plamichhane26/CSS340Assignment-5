#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility> 
#include <string>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h" // For std::pair

using namespace std;

// Template class for a Graph
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool isDirected = false)
    : V(vertices), directed(isDirected) {
    adjList.resize(V);
}

    // Add an edge
     void addEdge(int u, int v, T weight = T()) {
        if (u < 0 || u >= V || v < 0 || v >= V) return;
        if (u == v) return;

        adjList[u].append({v, weight});
        if (!directed) adjList[v].append({u, weight});
    }                   

    // Get number of nodes
    int getNumVertices() const{
        return V;
    }
   

    // Print the adjacency list
    void printGraph() const {
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
    vector<pair<int, T>> getNeighbors(int vertex) const {
        if (vertex < 0 || vertex >= V) return {};
        return adjList[vertex].toVector();
    }
    // Depth First Traversal

    void DFT(int start, const vector<Event>& events) const {
        if (start < 0 || start >= V) return;
        vector<bool> visited(V, false);
        DFTRecursive(start, visited, events);
        cout << endl;
    }

     void DFTRecursive(int v, vector<bool>& visited, const vector<Event>& events) const {

    // -----------------------------------------------------
    // Depth First Search (by username)
    // TO DO 
    // Add DFS prototype 
    // Add DFSRecursive prototype
    
        visited[v] = true;
        cout << events[v] << endl;

        auto neighbors = adjList[v].toVector();
        for (const auto& n : neighbors) {
            int next = n.first;
            if (!visited[next]) DFTRecursive(next, visited, events);
        }
    }

    bool DFS(const string& eventName, const vector<Event>& events, int start = 0) const {
        if (start < 0 || start >= V) return false;
        vector<bool> visited(V, false);
        return DFSRecursive(start, eventName, visited, events);
    }

     bool DFSRecursive(int v, const string& name, vector<bool>& visited, const vector<Event>& events) const {
        visited[v] = true;
        if (events[v].getName() == name) return true;

        auto neighbors = adjList[v].toVector();
        for (const auto& n : neighbors) {
            int next = n.first;
            if (!visited[next]) {
                if (DFSRecursive(next, name, visited, events)) return true;
            }
        }
        return false;
    }

    

   
    private:
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
     vector<LinkedBag<pair<int, T>>> adjList;  // Adjacency list
};

// Include the implementation of template functions


#endif // GRAPH_H
