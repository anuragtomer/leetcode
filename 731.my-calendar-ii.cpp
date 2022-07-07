#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyCalendarTwo {

    struct Node {
        int start;
        int end;
        int k;
        Node *left, *right;
        Node(int _start, int _end, int _k) : start(_start), end(_end), k(_k) {
            left = nullptr;
            right = nullptr;
        };
    };

    Node *root;

    int query(Node *root, int start, int end) {
        if (start >= end || root == nullptr)
            return 0;
        if (root->start >= end)
            return query(root->left, start, end);
        if (root->end <= start)
            return query(root->right, start, end);
        return max(root->k, max(query(root->left, start, end), query(root->right, start, end)));
    }

    Node *update(Node *root, int start, int end) {
        if (start >= end)
            return root;
        if (root == nullptr)
            return new Node(start, end, 1);
        if (root->end <= start)
            root->right = update(root->right, start, end);
        else if (root->start >= end)
            root->left = update(root->left, start, end);
        else {
            int a = min(start, root->start);
            int b = max(start, root->start);
            int c = min(end, root->end);
            int d = max(end, root->end);
            root->start = b;
            root->end = c;
            root->k++;
            root->left = update(root->left, a, b);
            root->right = update(root->right, c, d);
        }
        return root;
    }

   public:
    MyCalendarTwo() { root = nullptr; }

    bool book(int start, int end) {
        if (query(root, start, end) >= 2)
            return false;
        root = update(root, start, end);
        return true;
    }
};
int main() {
    MyCalendarTwo *obj = new MyCalendarTwo();
    assert(obj->book(10, 20));
    assert(obj->book(50, 60));
    assert(obj->book(10, 40));
    assert(!obj->book(5, 15));
    assert(obj->book(5, 10));
    assert(obj->book(25, 55));
    return 0;
}

