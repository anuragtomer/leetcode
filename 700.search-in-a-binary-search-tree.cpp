#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
   public:
    // Recursive
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;
        return (root->val < val) ? searchBST(root->right, val) : searchBST(root->left, val);
    }
    /* Iterative */
    /* 
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root) {
            if (root->val == val)
                return root;
            root = (root->val < val) ? root->right : root->left;
        }
        return nullptr;
    } 
    */
};

int main() {
    Solution sol;
    string input = "4,2,7,1,3";
    TreeNode *root = createTree(input, ',');
    TreeNode *output = sol.searchBST(root, 2);
    input = "2,1,3";
    TreeNode *expected = createTree(input, ',');
    compareTrees(output, expected);
    return 0;
}
