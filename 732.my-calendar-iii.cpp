#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyCalendarThree {
    struct Node {
        int start;
        int end;
        int k;
        Node *left;
        Node *right;
        Node(int _start, int _end, int _k) {
            start = _start;
            end = _end;
            k = _k;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;
    int maxCollisions = 0;
    Node *update(Node *root, int start, int end, int count) {
        if (!root) {
            maxCollisions = max(maxCollisions, count);
            root = new Node(start, end, count);
            return root;
        }
        if (end <= root->start)
            root->left = update(root->left, start, end, count);
        else if (start >= root->end)
            root->right = update(root->right, start, end, count);
        else {
            int a = min(root->start, start);
            int b = max(root->start, start);
            int c = min(root->end, end);
            int d = max(root->end, end);
            if (a < b)
                root->left = update(root->left, a, b, start < root->start ? count : root->k);

            if (c < d)
                root->right = update(root->right, c, d, end > root->end ? count : root->k);

            root->start = b;
            root->end = c;
            root->k += count;
            maxCollisions = max(maxCollisions, root->k);
        }
        return root;
    }

   public:
    MyCalendarThree() { root = nullptr; }

    int book(int start, int end) {
        root = update(root, start, end, 1);
        return maxCollisions;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
int main() { return 0; }

