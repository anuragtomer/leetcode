#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
   public:
    int maxDepth(Node *root) {
        if (root == nullptr)
            return 0;
        vector<pair<Node *, int>> q;
        int i = 0;
        q.push_back({root, 1});
        int lastLevel = 1;
        while (i < q.size()) {
            auto [node, level] = q[i];
            ++i;
            lastLevel = max(lastLevel, level);
            for (auto child : node->children) {
                if (child != nullptr) {
                    q.push_back({child, level + 1});
                }
            }
        }
        return lastLevel;
    }
};

int main() {
    Solution sol;

    return 0;
}

