#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
    TreeNode *bstFromPreorder(vector<int> &preorder, int &index, int limit) {
        if (index >= preorder.size() || preorder[index] > limit)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[index]);
        index++;
        root->left = bstFromPreorder(preorder, index, root->val);
        root->right = bstFromPreorder(preorder, index, limit);
        return root;
    }

   public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int index = 0;
        return bstFromPreorder(preorder, index, INT_MAX);
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    int i = 0;
    vector<int> vec(n);
    while (n--) {
        cin >> vec[i++];
    }
    TreeNode *root = sol.bstFromPreorder(vec);
    printLevelTree(root);
    return 0;
}
