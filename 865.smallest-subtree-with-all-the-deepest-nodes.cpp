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
    bool ifLeaf(TreeNode *root) { return root && !root->left && !root->right; }
    struct details {
        TreeNode *node = nullptr;
        int depth = 0;
    };

    details helper(TreeNode *root, int depth) {
        if (!root)
            return {root, depth - 1};
        if (ifLeaf(root))
            return {root, depth};
        auto leftDetails = helper(root->left, depth + 1);
        auto rightDetails = helper(root->right, depth + 1);
        details result;
        if (leftDetails.depth > rightDetails.depth) {
            result.depth = leftDetails.depth;
            result.node = leftDetails.node;
        } else if (leftDetails.depth < rightDetails.depth) {
            result.depth = rightDetails.depth;
            result.node = rightDetails.node;
        } else {
            result.depth = rightDetails.depth;
            result.node = root;
        }
        return result;
    }

   public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        if (!root)
            return root;
        auto details = helper(root, 0);
        return details.node;
    }
};

int main() {
    Solution sol;

    return 0;
}

