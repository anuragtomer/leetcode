#include "../../include/utility.h"
using namespace std;

class Solution {
    void isCousins(TreeNode *root, int x, int &xdepth, TreeNode *&xparent, int y, int &ydepth, TreeNode *&yparent) {
        if (!root)
            return;
        int localxDepth = xdepth, localyDepth = ydepth;
        if (xparent == nullptr) {
            xdepth++;
            if ((root->left && root->left->val == x) || (root->right && root->right->val == x))
                xparent = root;
        }
        if (yparent == nullptr) {
            ydepth++;
            if ((root->left && root->left->val == y) || (root->right && root->right->val == y))
                yparent = root;
        }
        if (xparent == nullptr || yparent == nullptr) {
            isCousins(root->left, x, xdepth, xparent, y, ydepth, yparent);
            if (xparent == nullptr)
                xdepth = localxDepth + 1;
            if (yparent == nullptr)
                ydepth = localyDepth + 1;
            if (xparent == nullptr || yparent == nullptr)
                isCousins(root->right, x, xdepth, xparent, y, ydepth, yparent);
        }
    }

   public:
    bool isCousins(TreeNode *root, int x, int y) {
        TreeNode *xparent = nullptr, *yparent = nullptr;
        int xdepth = 0, ydepth = 0;
        if (root && root->val == x)
            xparent = root;
        if (root && root->val == y)
            yparent = root;
        isCousins(root, x, xdepth, xparent, y, ydepth, yparent);
        return (xdepth == ydepth) && (xparent != yparent);
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = createTree(nums);
    assert(sol.isCousins(root, 3, 4) == false);
    assert(sol.isCousins(root, 4, 5) == false);
    assert(sol.isCousins(root, 4, 6) == true);
    deleteTree(root);
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(4);
    root->right->left->right->right = new TreeNode(5);
    assert(false == sol.isCousins(root, 1, 3));
    deleteTree(root);
    return 0;
}
