#include <iostream>
#include <cmath>
#include "graph.h"
#include "prim.h"

using namespace std;

int main() {

    int n_power = 1; // Power of 10 for the number of vertices

    // Generating a random graph with 4 vertices, 6 edges, and max weight 10
//    WeightedGraph graph = randGraph(pow(10, n_power)+1, 5, 10);

    WeightedGraph graph = randGraph(5+1, 2, 10);

    // Printing the random graph
    cout << "rozmiar: 10^" << n_power << endl;
    cout << "graf: " << endl;
    graph.printGraph();

    WeightedGraph MST = prim(graph);

    cout << "\npriorytetowa: " << endl;
    MST.printGraph();

    return 0;
}
