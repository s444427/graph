#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

list<Edge> weight_vec;

// Prim's Algorithm
WeightedGraph prim(WeightedGraph graph) {

    // Define structures
    int vertices = graph.getVertices();
    WeightedGraph MST(vertices); // Minimum Spanning Tree

    vector<int> key(vertices, INT_MAX); // Key values used to pick the minimum weight edge
    vector<int> parent(vertices, -1);   // To store the constructed MST
    vector<bool> inMST(vertices, false); // To represent set of vertices included in MST

    // Start with the first vertex
    key[0] = 1;

    cout << "start the Prim"<<endl;

    vector<list<Edge>> adjacencyList;
    adjacencyList = graph.getAdjacencyList();

    // Prim's algorithm
    for (int count = 0; count < vertices - 1; ++count) {
        // Find the minimum key vertex that is not yet included in MST
//        int u = minKey(key, inMST);
        int u = 0;

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

void priorityQueue(list<Edge> added_weights){

    cout << "Starting Queue: ";

    // print weight_vec
    for (auto i : weight_vec) {
        cout << i.weight << ' ';
    }

    int top_val = 0;
    int top_source = 0;
    int top_dest = 0;

    // defining priority queue
    priority_queue<int> pq;

    // pushing array sequentially one by one
    for (auto i : weight_vec) {
        pq.push(i.weight);
    }

    // printing priority queue
    cout << "\nPriority Queue: " << endl;
    while (!pq.empty()) {
        top_val = pq.top();
        top_source = 0;
        top_dest = 0;

        for (auto i : weight_vec) {
            if (i.weight == top_val){
                top_source = i.source;
                top_dest = i.destination;
                break;
            }
        }

        cout << top_val << ' ' << top_source << ' '<< top_dest << endl;
        pq.pop();
    }
}