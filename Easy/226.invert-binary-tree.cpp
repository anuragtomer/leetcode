#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root)
            return nullptr;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};

int main() {
    Solution sol;
    string s = "4,2,7,1,3,6,9";
    TreeNode *root = createTree(s, ',');
    printLevelTree(root);
    root = sol.invertTree(root);
    cout << "\n";
    printLevelTree(root);
    return 0;
}
