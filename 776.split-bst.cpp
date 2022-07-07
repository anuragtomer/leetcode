#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    vector<TreeNode *> splitBST(TreeNode *root, int V) {
        vector<TreeNode *> res(2, nullptr);
        if (!root)
            return res;

        if (root->val > V) {
            res[1] = root;
            auto r = splitBST(root->left, V); // V lies in the left half of the tree.
            root->left = r[1];                // Hence updating left of root.
            res[0] = r[0];                    // root of BST <= v should be r[0].
        } else {
            res[0] = root;
            auto r = splitBST(root->right, V);
            root->right = r[0];
            res[1] = r[1];
        }
        return res;
    }
};
int main() {
    Solution sol;

    return 0;
}

