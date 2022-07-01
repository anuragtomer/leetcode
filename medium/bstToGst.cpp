#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:    
    void postorder(TreeNode * root, int &currSum) {
        if (root) {
            postorder(root->right, currSum);
            currSum += root->val;
            root->val = currSum;
            postorder(root->left, currSum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int currSum = 0;
        postorder(root, currSum);
        return root;
    }
};

void
inorder(TreeNode * root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void
preorder(TreeNode * root) {
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    /*
     [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
                     4
                /         \
               1           6
              / \         /  \
             0   2       5    7
                  \            \
                   3            8
     */
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    Solution sol;
    root = sol.bstToGst(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    return 0;
}