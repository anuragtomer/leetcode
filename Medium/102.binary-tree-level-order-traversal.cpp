#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root)
            return {};
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        int i = 0;
        vector<vector<int>> result;
        while (i < nodes.size()) {
            int len = nodes.size();
            vector<int> level;
            while (i < len) {
                level.push_back(nodes[i]->val);
                if (nodes[i]->left)
                    nodes.push_back(nodes[i]->left);
                if (nodes[i]->right)
                    nodes.push_back(nodes[i]->right);
                ++i;
            }
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

