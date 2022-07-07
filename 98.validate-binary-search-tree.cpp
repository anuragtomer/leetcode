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
    bool helper(TreeNode *root, long min, long max) {
        if (!root)
            return true;
        if ((root->val > min) && (root->val < max)) {
            return helper(root->left, min, root->val) && helper(root->right, root->val, max);
        }
        return false;
    }

   public:
    bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    assert(sol.isValidBST(root) == true);
    delete (root->right);
    delete (root->left);
    delete (root);
    root = new TreeNode(1);
    root->left = new TreeNode(1);
    assert(false == sol.isValidBST(root));
    delete (root->left);
    delete root;
    root = new TreeNode(1);
    root->right = new TreeNode(1);
    assert(false == sol.isValidBST(root));
    delete root->right;
    delete root;
    root = new TreeNode(2147483647);
    assert(true == sol.isValidBST(root));
    delete root;
    return 0;
}

