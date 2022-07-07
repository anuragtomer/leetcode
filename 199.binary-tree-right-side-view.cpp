#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    vector<int> rightSideView(TreeNode *root) {
        vector<pair<TreeNode *, int>> level;
        vector<int> result;
        level.push_back({root, 0});
        for (int i = 0; i < level.size(); ++i) {
            auto [node, currentLevel] = level[i];
            if (currentLevel == result.size())
                result.push_back(node->val);
            if (node->right)
                level.push_back({node->right, currentLevel + 1});
            if (node->left)
                level.push_back({node->left, currentLevel + 1});
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

