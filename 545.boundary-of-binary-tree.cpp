#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};
class Solution {
    void findLefts(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        if (!root->left && !root->right) // This is a leaf node.
            return;
        if (root->left || root->right)
            result.push_back(root->val);
        if (root->left)
            findLefts(root->left, result);
        else
            findLefts(root->right, result);
    }

    void findRights(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        if (!root->left && !root->right) // This is leaf node.
            return;
        if (root->right)
            findRights(root->right, result);
        else
            findRights(root->left, result);
        if (root->left || root->right)
            result.push_back(root->val);
    }

    void findLeafs(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        if (!root->left && !root->right)
            result.push_back(root->val);
        if (root->left)
            findLeafs(root->left, result);
        if (root->right)
            findLeafs(root->right, result);
    }

   public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        if (!root)
            return vector<int>();
        vector<int> result;
        result.push_back(root->val);
        findLefts(root->left, result);
        findLeafs(root, result);
        findRights(root->right, result);
        return result;
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    vector<int> output = sol.boundaryOfBinaryTree(root);
    vector<int> result = {1, 3, 4, 2};
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i] == result[i]);
    }
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}

