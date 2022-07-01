#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
    int diameterOfBinaryTree(TreeNode *root, int &maxDiameter) {
        if (!root)
            return 0;
        int leftDepth = diameterOfBinaryTree(root->left, maxDiameter);
        int rightDepth = diameterOfBinaryTree(root->right, maxDiameter);
        if (maxDiameter < leftDepth + rightDepth)
            maxDiameter = leftDepth + rightDepth;
        return max(leftDepth, rightDepth) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode *root) {
        int maxDiameter = 0;
        diameterOfBinaryTree(root, maxDiameter);
        return maxDiameter;
    }
};

int main() {
    TreeNode *root;
    Solution sol;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    assert(3 == sol.diameterOfBinaryTree(root));

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->left->left->right = new TreeNode(8);
    root->left->right->right->right = new TreeNode(9);
    cout << sol.diameterOfBinaryTree(root);
    assert(6 == sol.diameterOfBinaryTree(root));

    delete root->left->left->left->right;
    delete root->left->right->right;
    delete root->left->left->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}