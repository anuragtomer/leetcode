#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    string findDuplicateSubtree(TreeNode *root, unordered_map<string, TreeNode *> &preorderToTreeRoot,
                                unordered_map<string, bool> &pushedInResult, vector<TreeNode *> &result) {
        if (!root) {
            return "";
        }
        string left = findDuplicateSubtree(root->left, preorderToTreeRoot, pushedInResult, result);
        string current = left + "," + to_string(root->val) + ",";
        string right = findDuplicateSubtree(root->right, preorderToTreeRoot, pushedInResult, result);
        current = current + right + ",";
        if (preorderToTreeRoot.find(current) != preorderToTreeRoot.end()) {
            if (pushedInResult[current] == false)
                result.push_back(root);
            pushedInResult[current] = true;
        } else {
            pushedInResult[current] = false;
            preorderToTreeRoot[current] = root;
        }
        return current;
    }

   public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        if (!root)
            return vector<TreeNode *>();
        unordered_map<string, TreeNode *> preorderToTreeRoot;
        unordered_map<string, bool> pushedInResult;
        vector<TreeNode *> result;
        string temp = findDuplicateSubtree(root, preorderToTreeRoot, pushedInResult, result);
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

