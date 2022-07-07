#include "lib.h"

class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (sum == root->val && !root->left && !root->right)
            return true;
        else
            return (hasPathSum(root->left, sum-(root->val)) ||
                    hasPathSum(root->right, sum-(root->val)));
    }
};

int main(){
    Solution sol;
    TreeNode * root = createTree();
    int sum = 0;
    cin >> sum;
    if (sol.hasPathSum(root, sum)) cout << "True";
    else cout << "False";
	return 0;
}
