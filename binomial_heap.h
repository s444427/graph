#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

class BinomialHeap {
private:
    list<Edge> weight_vec;
    vector<bool> inMST;

    struct Node {
        int key;
        Node *parent;
        Node *child;
        Node *sibling;
        int degree;
    };

    Node *H;

    Node *makeHeap() {
        Node *heap;
        heap = nullptr;
        return heap;
    }

    Node *makeHeap(int k) {
        Node *heap;
        heap = new Node;
        heap->key = k;
        heap->degree = 0;
        heap->parent = nullptr;
        heap->child = nullptr;
        heap->sibling = nullptr;
        return heap;
    }

    Node *merge(Node *H1, Node *H2) {
        Node *H = makeHeap();
        Node *x, *y, *z;
        x = H1;
        y = H2;
        if (x != nullptr) {
            if (y != nullptr && y->degree <= x->degree) {
                H = x;
            } else {
                H = y;
            }
        } else {
            H = y;
        }

        while (x != nullptr && y != nullptr) {
            if (x->degree < y->degree) {
                x = x->sibling;
            } else if (x->degree == y->degree) {
                z = x->sibling;
                x->sibling = y;
                x = z;
            } else {
                z = y->sibling;
                y->sibling = x;
                y = z;
            }
        }
        return H;
    }

    void link(Node *y, Node *z) {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree++;
    }

    Node *unionHeap(Node *H1, Node *H2) {
        Node *prev_x, *next_x, *x;
        Node *H = makeHeap();
        H = merge(H1, H2);

        if (H == nullptr) {
            return H;
        }
        prev_x = nullptr;
        x = H;
        next_x = x->sibling;
        while (next_x != nullptr) {
            if ((x->degree != next_x->degree) ||
                ((next_x->sibling != nullptr) && (next_x->sibling)->degree == x->degree)) {
                prev_x = x;
            };
        };
    }

    Node *insert(Node *H, int k) {
        Node *x = makeHeap(k);
        return unionHeap(H, x);
    }

    Node *extractMin(Node *H) {
        Node *y = nullptr;
        Node *x = H;
        int min = INT_MAX;
        while (x != nullptr) {
            if (x->key < min) {
                min = x->key;
                y = x;
            }
            x = x->sibling;
        }
        return y;
    }

    void decreaseKey(Node *H, Node *x, int k) {
        if (k > x->key) {
            cout << "ERROR zwiększenie wartości klucza" << endl;
            return;
        }
        x->key = k;
        Node *y = x;
        Node *z = y->parent;
        while (z != nullptr && y->key < z->key) {
            int temp = y->key;
            y->key = z->key;
            z->key = temp;
            y = z;
            z = y->parent;
        }
    }

    Node *deleteKey(Node *H, Node *x) {
        decreaseKey(H, x, INT_MIN);
        return extractMin(H);
    }

public:
// Constructor
    BinomialHeap(int vertices) : weight_vec(), H(), inMST(vertices, false) {}

    // Getters
    const list<Edge> getWeightVec() const {
        return weight_vec;
    }

//    // Setters
//    void addEdges(list<Edge> edge_list, Node H) {
//        for (auto edge : edge_list) {
//            insert( *H, edge.weight);         // negative sign to make it min queue
//            weight_vec.push_back(edge);    // store source and destination
//        }
//    }

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
    }
};