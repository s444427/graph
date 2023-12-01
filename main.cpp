#include <iostream>
#include <cmath>
#include "graph.h"

using namespace std;

int main() {
    int n_power = 1; // Power of 10 for the number of vertices

    // Generating a random graph with 4 vertices, 6 edges, and max weight 10
    WeightedGraph graph = WeightedGraph::randGraph(pow(10, n_power)+1, 5*pow(10, n_power), 10);

    // Printing the random graph
    cout << "Random Graph:" << endl;
    graph.printGraph();

    return 0;
}
