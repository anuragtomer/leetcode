#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
   public:
    int sumLeafNode(TreeNode *root) {
        if (!root)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        int sum = 0;
        if (root->left != nullptr)
            sum += sumLeafNode(root->left);
        if (root->right != nullptr)
            sum += sumLeafNode(root->right);
        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}

