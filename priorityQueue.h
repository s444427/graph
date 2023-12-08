#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

// Weighted Graph class
class PriorityQueue {

private:
    list<Edge> weight_vec;
    priority_queue<int> pq;
    vector<bool> inMST;

public:
    // Constructor
    PriorityQueue(int vertices) : weight_vec(), pq(), inMST(vertices, false) {}

    // Getters
    const list<Edge> getWeightVec() const {
        return weight_vec;
    }

    const priority_queue<int> getPQ() const {
        return pq;
    }

    // Setters
    void addEdges(list<Edge> edge_list) {
        for (auto edge : edge_list) {
            pq.push(-edge.weight);         // negative sign to make it min queue
            weight_vec.push_back(edge);    // store source and destination
        }
    }

    void setFlag(int v) {
        inMST[v] = true;
    }

    void removeEdge(int weight) {
        auto it = weight_vec.begin();

        while(it->weight != weight){
            advance(it, 1);
        }
        weight_vec.erase(it);
    }

    // Methods
    // Function to print the queue
    void printQueue() {
        cout << "Weight vec elements:" << endl;
        for (auto i : weight_vec) {
            cout << i.source << ' ' << i.destination << ' ' << i.weight << endl;
        }

        priority_queue<int> pqCopy = pq;
        cout << "Priority Queue elements: ";
        while (!pqCopy.empty()) {
            cout << pqCopy.top() << " "; // Access the top element
            pqCopy.pop(); // Remove the top element from the copy
        }
        cout << endl;
    }

    Edge getMin() {
        bool flag = false;

        int min_source;
        int min_dest;
        int min_weight;

        while (!flag) {
//            printQueue();
            min_weight = -pq.top(); // negative sign to revoke the real min queue value
            pq.pop();

            min_source = 0;
            min_dest = 0;

            // list of source and destination
            for (auto i : weight_vec) {
                if (i.weight == min_weight){
                    min_source = i.source;
                    min_dest = i.destination;

                    // remove the edge from the queue
                    removeEdge(min_weight);
                    break;
                }
            }

//            cout << "Minimum Edge: " << "s: " << min_source << " d: " << min_dest << " w: " << min_weight << endl;

            if (!inMST[min_dest])
                flag = true;
//            else
//                cout << "Edge already in MST" << endl;
        }

//        printQueue();
        return Edge(min_source, min_dest, min_weight);
    }

};