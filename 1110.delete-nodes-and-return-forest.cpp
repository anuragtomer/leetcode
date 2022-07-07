#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
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
/*
class Solution {
    void traverseAndRemove(TreeNode *root, unordered_set<TreeNode *> &possibleRoots) {
        queue<TreeNode *> tempQ;
        tempQ.push(root);
        while (!tempQ.empty()) {
            TreeNode *top = tempQ.front();
            if (possibleRoots.count(top))
                possibleRoots.erase(top);
            tempQ.pop();
            if (top->left) {
                if (possibleRoots.count(top->left))
                    tempQ.push(top->left);
                else
                    top->left = nullptr;
            }
            if (top->right) {
                if (possibleRoots.count(top->right))
                    tempQ.push(top->right);
                else
                    top->right = nullptr;
            }
        }
    }

   public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> nodes;
        if (!root)
            return {};
        unordered_set<int> deleteList(to_delete.begin(), to_delete.end());
        unordered_set<TreeNode *> possibleRoots;
        nodes.push_back(root);
        int i = 0;
        while (i < nodes.size()) {
            TreeNode *node = nodes[i];
            if (!deleteList.count(node->val))
                possibleRoots.insert(node);
            if (node->left)
                nodes.push_back(node->left);
            if (node->right)
                nodes.push_back(node->right);
            ++i;
        }
        vector<TreeNode *> result;
        i = 0;
        while (i < nodes.size()) {
            TreeNode *node = nodes[i];
            ++i;
            if (possibleRoots.count(node)) {
                result.push_back(node);
                traverseAndRemove(node, possibleRoots);
            }
        }
        return result;
    }
};
*/
class Solution {
   public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        unordered_set<int> deletionSet(to_delete.begin(), to_delete.end());
        vector<TreeNode *> result;
        helper(root, deletionSet, result, true);
        return result;
    }
    TreeNode *helper(TreeNode *root, unordered_set<int> &deletionSet, vector<TreeNode *> &result, bool isRoot) {
        if (!root)
            return root;
        bool shouldDelete = deletionSet.find(root->val) != deletionSet.end();
        if (isRoot && !shouldDelete)
            result.push_back(root);
        root->left = helper(root->left, deletionSet, result, shouldDelete);
        root->right = helper(root->right, deletionSet, result, shouldDelete);
        return shouldDelete ? nullptr : root;
    }
};

int main() {
    Solution sol;

    return 0;
}

