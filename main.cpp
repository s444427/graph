#include <iostream>
#include <cmath>
#include "graph.h"
#include "prim.h"

using namespace std;



int main() {

    int n_power = 1; // Power of 10 for the number of vertices

    // Generating a random graph with 4 vertices, 6 edges, and max weight 10
    WeightedGraph graph = randGraph(pow(10, n_power)+1, 5, 10);

    // Printing the random graph
    cout << "Random Graph:" << endl;
    graph.printGraph();
    cout<<"DONE"<<endl;


    weight_vec = graph.getNeighbours(1);
    priorityQueue(weight_vec);

//    WeightedGraph MST = prim(graph);

//    cout << "\nMinimum Spanning Tree (Prim's Algorithm):" << endl;
//    MST.printGraph();

    return 0;
}
