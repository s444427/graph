#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

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

    // Function to add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        Edge newEdge(destination, weight);
        adjacencyList[source].push_back(newEdge);

//        Edge newEdgeBack(source, weight);
//        adjacencyList[destination].push_back(newEdgeBack);
    }

    // Function to add a vertex to the graph
    void addVertex() {
        ++vertices;
        adjacencyList.push_back(list<Edge>());
    }

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

    // Function to generate a random graph
    static WeightedGraph randGraph(int v_n, int e_n, int max_w) {
        WeightedGraph G(v_n);

        srand(static_cast<unsigned>(time(0))); // Seed the random number generator

        for (int i = 0; i < v_n; ++i) {
            int r = rand() % e_n + 1;
            int j = 1;

            while (j <= i - 1 && j <= r) {
                int v = rand() % i;
                int w = rand() % max_w + 1;

                G.addEdge(v, i, w);

                ++j;
            }
        }

        return G;
    }
};