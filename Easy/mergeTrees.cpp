/* Aim is to merge two given trees.
 * If both trees have a node at same place, new tree should have a node with a value of aggregate
 * of both. Otherwise, new tree should have a node with value of non-null node of either of two 
 * trees.
 */
#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode * copyTree(TreeNode * t) {
        if (t == nullptr) {
            return nullptr;
        } else {
            TreeNode * newT = new TreeNode(t->val);
            newT->left = copyTree(t->left);
            newT->right = copyTree(t->right);
            return newT;
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode * root = nullptr;
        if (t1 != nullptr && t2 != nullptr) {
            root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        } else if (t1 == nullptr && t2 != nullptr) {
            root = copyTree(t2);
        } else if (t1 != nullptr && t2 == nullptr) {
            root = copyTree(t1);
        }
        return root;
    }
};