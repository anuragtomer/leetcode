#include "../lib.h"

class Solution{
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};

int main(){
    Solution sol;
    TreeNode * root = createTree();
    cout << sol.maxDepth(root);
	return 0;
}
