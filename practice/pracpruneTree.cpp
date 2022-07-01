#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root) {
            if (root->val == 0 && root->left == NULL && root->right == NULL) {
                return NULL;
            }
            if (root->left)
                root->left = pruneTree(root->left);
            if (root->right)
                root->right = pruneTree(root->right);
            if (root->left == NULL && root->right == NULL && root->val == 0) {
                return NULL;
            }
        }
        return root;
    }
};

int main() {
    Solution sol;

    return 0;
}


