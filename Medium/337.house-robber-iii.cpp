#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    struct data {
        int robbery;
        int norobbery;
    };
    data helper(TreeNode *root) {
        if (!root)
            return {0, 0};
        data left = helper(root->left);
        data right = helper(root->right);
        data result;
        result.robbery = root->val + left.norobbery + right.norobbery;
        result.norobbery = max(left.robbery, left.norobbery) + max(right.robbery, right.norobbery);
        return result;
    }

   public:
    int rob(TreeNode *root) {
        data d = helper(root);
        return max(d.robbery, d.norobbery);
    }
};

int main() {
    Solution sol;

    return 0;
}

