#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>
#include "priorityQueue.h"

using namespace std;


// Prim's Algorithm
WeightedGraph prim(WeightedGraph graph) {

    // Define structures
    int vertices = graph.getVertices(); // Number of vertices in the graph

    WeightedGraph MST(vertices); // Minimum Spanning Tree
    PriorityQueue priority_queue(vertices);

    priority_queue.setFlag(1);

    // Start with the first vertex
    int chosen_vertex = 1;

    for (int i=1; i<vertices - 1; i++ ){
//        cout << endl << "Iteration #"<<i<<endl;

        priority_queue.addEdges(graph.getNeighbours(chosen_vertex));
        Edge min_edge = priority_queue.getMin();

        chosen_vertex = min_edge.destination;
        priority_queue.setFlag(chosen_vertex);

        MST.addEdge(min_edge.source, min_edge.destination, min_edge.weight); // Add the edge to the MST
        MST.addEdge(min_edge.destination, min_edge.source, min_edge.weight); // Add the edge to the MST
    }


    return MST;
}
