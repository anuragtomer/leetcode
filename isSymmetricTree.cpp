#include "lib.h"
#include <cassert>

class Solution{
public:
    bool isSymmetricChildren(TreeNode * left, TreeNode * right) {
        if (left && right) {
            if (left->val == right->val) {
                return (isSymmetricChildren(left->left, right->right) &&
                       isSymmetricChildren(left->right, right->left));
            }
            return false;
        }
        if (!left && !right) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right)
                return true;
            if ((root->left && !root->right) ||
                (root->right && !root->left))
                return false;
            return isSymmetricChildren(root->left, root->right);
        }
        return true;
    }
};

int main(){
    Solution sol;
    TreeNode * root;
    root = createTree();
    if (sol.isSymmetric(root)) cout << "True";
    else cout << "False";
	return 0;
}
