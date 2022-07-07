#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};
class Solution {
    void helper(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &allPaths) {
        if (!root)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right) {
            allPaths.push_back(path);
            return;
        }
        helper(root->left, targetSum, path, allPaths);
        helper(root->right, targetSum, path, allPaths);
    }

   public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        vector<vector<int>> allPaths;
        helper(root, targetSum, path, allPaths);
        return allPaths;
    }
};

int main() {
    Solution sol;

    return 0;
}

