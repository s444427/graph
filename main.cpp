#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    // Generating a random graph with 4 vertices, 6 edges, and max weight 10
    WeightedGraph graph = WeightedGraph::randGraph(4, 6, 10);

    // Printing the random graph
    cout << "Random Graph:" << endl;
    graph.printGraph();

    return 0;
}
