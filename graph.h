#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Weighted Graph class
class WeightedGraph {

private:
    int vertices; // Number of vertices in the graph
    vector<list<Edge>> adjacencyList; // Adjacency list to store edges

public:
    // Constructor
        WeightedGraph(int v) : vertices(v), adjacencyList(v) {}

    // Getters
        int getVertices() const {
            return vertices;
        }

    // Setters
        // Function to add a vertex to the graph
        void addVertex() {
            ++vertices;
            adjacencyList.push_back(list<Edge>());
        }

        // Function to add an edge to the graph
        void addEdge(int source, int destination, int weight) {
            Edge newEdge(destination, weight);
            adjacencyList[source].push_back(newEdge);
        }

    // Methods
        // Function to print the graph
        void printGraph() {
            for (int i = 0; i < vertices; ++i) {
                cout << "Vertex " << i << ": ";
                for (const Edge& edge : adjacencyList[i]) {
                    cout << "(" << edge.destination << ", " << edge.weight << ") ";
                }
                cout << endl;
            }
        }

};


// Function to generate a random graph
WeightedGraph randGraph(int vertices_number, int edges_max, int weight_max) {
    WeightedGraph G(vertices_number);

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (int i = 1; i < vertices_number; ++i) {
        int r = rand() % edges_max + 1;
        int j = 1;

        while (j <= i - 1 && j <= r) {
            int v = rand() % (i-1) + 1;
            int w = rand() % weight_max + 1;

            G.addEdge(v, i, w);
            G.addEdge(i, v, w);

            ++j;
        }
    }

    return G;
}


// Prim's Algorithm
WeightedGraph prim(WeightedGraph graph) {
    int vertices = graph.getVertices();

    WeightedGraph MST(vertices); // Minimum Spanning Tree

    vector<int> key(vertices, INT_MAX); // Key values used to pick the minimum weight edge
    vector<int> parent(vertices, -1);   // To store the constructed MST
    vector<bool> inMST(vertices, false); // To represent set of vertices included in MST

    // Start with the first vertex
    key[0] = 1;

    cout << "start the Prim"<<endl;

    // Prim's algorithm
    for (int count = 0; count < vertices - 1; ++count) {
        // Find the minimum key vertex that is not yet included in MST
        int u = minKey(key, inMST);

        // Add the picked vertex to the MST
        inMST[u] = true;

        // Update key value and parent index of adjacent vertices
        for (const Edge &edge : adjacencyList[u]) {
            int v = edge.destination;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    cout << "end the Prim"<<endl;


    // Add edges to the MST
    for (int i = 1; i < vertices; ++i) {
        MST.addEdge(parent[i], i, key[i]);
        MST.addEdge(i, parent[i], key[i]);
    }

    return MST;
}

// Helper function to find the vertex with the minimum key value
int minKey(const vector<int> &key, const vector<bool> &inMST) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < vertices; ++v) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}