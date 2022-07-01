/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node. 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
class BSTIterator {
    stack<TreeNode *> st;
    void populateStack(TreeNode * root) {
        if (root != nullptr)
            st.push(root);
        while(root != nullptr && root->left != nullptr) {
            st.push(root->left);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        populateStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        if (st.empty() == true) {
            return -1;
        } else {
            TreeNode *tp = st.top();
            st.pop();
            if (tp->right)
                populateStack(tp->right);
            return tp->val;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(st.empty());
    }
};
// @lc code=end
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
	TreeNode * root = new TreeNode(7);
	root->left = new TreeNode(3);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(12);
	BSTIterator it = BSTIterator(root);
    while(it.hasNext() == true)
        cout << it.next() << "\t";
    cout << "\n";
    return 0;
}
