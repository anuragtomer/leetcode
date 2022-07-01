#include <iostream>
#include <cassert>
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

class Solution {
public:
    int inorderTraversal(TreeNode * root, int &k) {
        int temp = INT_MIN;
        if (root != nullptr) {
            temp = inorderTraversal(root->left, k);
            if (k == 0)
                return temp;
            k--;
            if (k == 0)
                return root->val;
            temp = inorderTraversal(root->right, k);
            if (k == 0)
                return temp;
        }
        return temp;
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};

int main(void)
{
    Solution sol;
    TreeNode * root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    int count = 0;
    int total = 6;
    for(int i = 1; i <= 6; ++i)
        if (i == sol.kthSmallest(root, i)) {
            count++;
        }
    cout << count << "/"<< total << " test cases passed.\n";
    return 0;
}