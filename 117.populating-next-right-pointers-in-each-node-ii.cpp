#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
   public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};
/*
 * Solution 1 using extra datastructures(queue)
class Solution {
   public:
    queue<Node *> q1, q2;

   public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;
        q1.push(root);
        Node *last = nullptr;
        while (!q1.empty()) {
            auto current = q1.front();
            if (last != nullptr)
                last->next = current;
            q1.pop();
            if (current->left)
                q2.push(current->left);
            if (current->right)
                q2.push(current->right);
            if (q1.empty()) {
                q1.swap(q2);
                queue<Node *>().swap(q2);
                last = nullptr;
            } else
                last = current;
        }
        return root;
    }
};
*/
// Another solution without using datastructures.
class Solution {
   public:
    Node *connect(Node *root) {
        if (root) {
            if (root->left && root->right)
                root->left->next = root->right;
            auto next = root->next;
            while (next && next->left == nullptr && next->right == nullptr)
                next = next->next;
            if (next) {
                if (root->right)
                    root->right->next = next->left ? next->left : next->right;
                else if (root->left)
                    root->left->next = next->left ? next->left : next->right;
            }
            connect(root->right);
            connect(root->left);
        }
        return root;
    }
};
int main() {
    Solution sol;

    return 0;
}

