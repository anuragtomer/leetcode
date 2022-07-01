#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
    int sumNumbers(TreeNode *root, int currentSum) {
        if (!root->left && !root->right)
            return currentSum * 10 + root->val;
        else {
            int newSum = 0;
            currentSum = currentSum * 10 + root->val;
            if (root->left)
                newSum += sumNumbers(root->left, currentSum);
            if (root->right)
                newSum += sumNumbers(root->right, currentSum);
            return newSum;
        }
    }

   public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        return sumNumbers(root, 0);
    }
};

/**
 * Does not handle nullptr in between. Expects the tree to be left full.
 */
TreeNode *createTree(const vector<int> &nums) {
    TreeNode *root, *temp;
    if (nums.size() == 0)
        return nullptr;
    root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    for (int i = 1; i < nums.size(); i += 2) {
        TreeNode *curr = q.front();
        q.pop();
        curr->left = new TreeNode(nums[i]);
        q.push(curr->left);
        if (i + 1 < nums.size()) {
            curr->right = new TreeNode(nums[i + 1]);
            q.push(curr->right);
        }
    }
    return root;
}

void deleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        delete curr;
    }
}

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    TreeNode *root = createTree(nums);
    assert(25 == sol.sumNumbers(root));
    deleteTree(root);
    nums = {4, 9, 0, 5, 1};
    root = createTree(nums);
    assert(1026 == sol.sumNumbers(root));
    deleteTree(root);
    return 0;
}
