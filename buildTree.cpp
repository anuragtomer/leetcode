#include "lib.h"

class Solution{
public:
/*
// Create tree with given inorder and postorder traversal.
    void breakVector(vector<int> &inorder, int val, vector<int> &left, vector<int> &right) {
        bool r = false;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                r = true;
                continue;
            }
            if (r) {
                right.push_back(inorder[i]);
            } else {
                left.push_back(inorder[i]);
            }
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() > 0) {
            TreeNode * root = new TreeNode(postorder.back());
            vector<int> left, right;
            left.clear();
            right.clear();
            breakVector(inorder, postorder.back(), left, right);
            postorder.pop_back();
            root->right = buildTree(right, postorder);
            root->left = buildTree(left, postorder);
            return root;
        } else
            return NULL;
    }
*/
// Create tree with given inorder and preorder traversal.
void breakVector(vector<int> &inorder, int val, vector<int> &left, vector<int> &right) {
    bool r = false;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == val) {
            r = true;
            continue;
        }
        if (r) {
            right.push_back(inorder[i]);
        } else {
            left.push_back(inorder[i]);
        }
    }
}
void pop_front(vector<int> &preorder) {
    for(int i = 0; i < preorder.size() - 1; i++) {
        preorder[i] = preorder[i+1];
    }
    preorder.resize(preorder.size() - 1);
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
    if (inorder.size() > 0) {
        TreeNode * root = new TreeNode(preorder.front());
        vector<int> left, right;
        left.clear();
        right.clear();
        breakVector(inorder, preorder.front(), left, right);
        pop_front(preorder);
        root->left = buildTree(left, preorder);
        root->right = buildTree(right, preorder);
        return root;
    } else
        return NULL;
}
};

int main(){
    Solution sol;
    vector<int> inorder;
    inorder = createVector();
    vector<int> postorder;
    postorder = createVector();
    TreeNode * root;
    root = sol.buildTree(inorder, postorder);
    printTree(root);
	return 0;
}
