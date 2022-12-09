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
    /*
    void helper(TreeNode *root, vector<int> &nums) {
      if (!root)
        return ;
      helper(root->left, nums);
      nums.push_back(root->val);
      helper(root->right, nums);
    }*/
    void inorderTraversal(TreeNode *root, int &lastVal, int &minDiff) {
        if (root->left)
            inorderTraversal(root->left, lastVal, minDiff);
        if (lastVal >= 0)
            minDiff = min(minDiff, abs(root->val - lastVal));
        lastVal = root->val;
        if (root->right)
            inorderTraversal(root->right, lastVal, minDiff);
    }

   public:
    /*
    int getMinimumDifference(TreeNode* root) {
      vector<int> nums;
      helper(root, nums);
      int diff = INT_MAX;
      for (int i = 1 ; i < nums.size(); ++i)
        diff = min(diff, abs(nums[i] - nums[i-1]));
      return diff;
    }*/
    int getMinimumDifference(TreeNode *root) {
        int minDiff = INT_MAX, lastVal = -1;
        inorderTraversal(root, lastVal, minDiff);
        return minDiff;
    }
};

int main() {
    Solution sol;

    return 0;
}

