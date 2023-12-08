#include <iostream>
#include <cmath>
#include <chrono>

#include "graph.h"
#include "prim.h"
#include "binomial_heap.h"
#include "fibonacci_heap.h"

using namespace std;

int main() {
    int n_power;
    bool flags[3] = {false, false, false};
    double time_treshold = 0.1;

    for (int i=1; i<5; i++) {
        n_power = i; // Power of 10 for the number of vertices
        WeightedGraph graph = randGraph(pow(10, n_power)+1, 5, 100);

        cout << endl << "rozmiar: 10^" << n_power;

        if(n_power == 1) {
            cout << endl << "graf: " << endl;
            graph.printGraph();
        }

        if (!flags[0]) {
            auto startTime_pq = std::chrono::high_resolution_clock::now();
            WeightedGraph MST = prim(graph);
            auto endTime_pq = std::chrono::high_resolution_clock::now();
            auto duration_pq = std::chrono::duration_cast<std::chrono::microseconds>(endTime_pq - startTime_pq);
            float duration_pq_sec = round(duration_pq.count()/1000.0)/1000; // Time in seconds

            if(duration_pq_sec > time_treshold) {
                flags[0] = true;
            }

            cout << "\npriorytetowa: " << duration_pq_sec << endl;
            if(n_power == 1) {
                MST.printGraph();
            }

        }else{
            cout << "\npriorytetowa: 60+" << endl;
        }


    }

    return 0;
}
