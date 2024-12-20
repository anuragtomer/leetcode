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
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::vector<TreeNode *> level_nodes;
        bool odd_level = false;
        if (root) {
            level_nodes.push_back(root);
        }
        std::vector<TreeNode*> next_level;
        while (!level_nodes.empty()) {
            next_level.clear();
            for (const TreeNode * node : level_nodes) {
                if (node->left)
                    next_level.push_back(node->left);
                if (node->right)
                    next_level.push_back(node->right);
            }
            if (odd_level) {
                size_t num_nodes = level_nodes.size();
                for (size_t i = 0, j = num_nodes - 1; i < num_nodes/2; ++i, --j) {
                    swap(level_nodes[i]->val, level_nodes[j]->val);
                }
            }
            odd_level = !odd_level;
            level_nodes = std::move(next_level);
        }
        return root;
    }
};
