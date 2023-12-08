#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>


using namespace std;

class FibonacciHeap {
private:
    list<Edge> weight_vec;
    vector<bool> inMST;

    struct Node {
        int key;
        Node *parent;
        Node *child;
        Node *left;
        Node *right;
        int degree;
        bool mark;
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
        heap->left = heap;
        heap->right = heap;
        heap->mark = false;
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
                x = x->right;
            } else if (x->degree == y->degree) {
                z = y->right;
                y->right = x->right;
                y->left = x;
                x->right->left = y;
                x->right = y;
                x->degree = x->degree + 1;
                y = z;
            } else {
                z = y->right;
                y->right = x;
                y->left = x->left;
                x->left->right = y;
                x->left = y;
                y->degree = y->degree + 1;
                x = z;
            }
        }
        return H;
    }

    void insert(Node *H, Node *x) {
        Node *H1 = makeHeap();
        x->degree = 0;
        x->parent = nullptr;
        x->child = nullptr;
        x->left = x;
        x->right = x;
        x->mark = false;
        H1 = x;
        H = merge(H, H1);
    }

};