/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<TreeNode *> nodes;
        if (root) {
            nodes.push_back(root);
        }
        size_t total_swaps = 0;
        while (not nodes.empty()) {
            vector<TreeNode *> next_level;
            vector<pair<int, size_t>> level;
            size_t i = 0;
            for (const TreeNode * it: nodes) {
                level.push_back({it->val, i++});
                if (it->left) next_level.push_back(it->left);
                if (it->right) next_level.push_back(it->right);
            }
            sort(level.begin(), level.end());
            for (size_t i = 0; i < level.size(); ++i) {
                auto [val, index] = level[i];
                while (i != index) {
                    std::swap(level[i], level[index]);
                    index = level[i].second;
                    ++total_swaps;
                }
            }
            nodes = next_level;
        }
        return total_swaps;
    }
};
