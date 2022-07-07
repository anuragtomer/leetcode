#include "lib.h"

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        return (!left ? right: (!right? left: root));
    }
};

int main(){
    Solution sol;
    TreeNode * root = createTree();
    int int1, int2;
    cin >> int1;
    cin >> int2;
    TreeNode *p = new TreeNode(int1);
    TreeNode *q = new TreeNode(int2);
    TreeNode *res = lowestCommonAncestor(root, p, q);
    cout << res->val << ": left: " << res->left << "\n :right: " << res->right;
	return 0;
}
