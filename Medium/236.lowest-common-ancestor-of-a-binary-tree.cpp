#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    struct data {
        bool pmatch;
        bool qmatch;
        TreeNode *node;
    };
    data helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return {false, false, nullptr};

        auto leftData = helper(root->left, p, q);
        if (leftData.pmatch && leftData.qmatch)
            return leftData;

        auto rightData = helper(root->right, p, q);
        if (rightData.pmatch && rightData.qmatch)
            return rightData;

        data temp = {false, false, nullptr};
        if (root == p || leftData.pmatch || rightData.pmatch)
            temp.pmatch = true;
        if (root == q || leftData.qmatch || rightData.qmatch)
            temp.qmatch = true;
        if (temp.pmatch && temp.qmatch)
            temp.node = root;
        return temp;
    }

   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) { return helper(root, p, q).node; }
};
int main() {
    Solution sol;

    return 0;
}

