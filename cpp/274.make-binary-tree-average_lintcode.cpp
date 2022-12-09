#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
   public:
    int makeBinaryTreeAverage(TreeNode *root) { return dfs(root, false).second; }

    pair<float, int> dfs(TreeNode *node, bool fixed) {
        if (node == nullptr)
            return {-1, 0};
        if (node->left == nullptr && node->right == nullptr)
            return {node->val, 0};
        int minChanges = INT_MAX / 2;
        int changes = 0;
        float value, avg;

        if (fixed == false) {
            auto leftFree = dfs(node->left, false);
            auto rightFree = dfs(node->right, false);
            auto leftFixed = dfs(node->left, true);
            auto rightFixed = dfs(node->right, true);

            if (node->left && node->right)
                avg = (leftFree.first + rightFree.first) * 0.5;
            else if (node->left)
                avg = leftFree.first;
            else
                avg = rightFree.first;
            changes = leftFree.second + rightFree.second + (node->val == avg ? 0 : 1);
            if (changes < minChanges) {
                minChanges = changes;
                value = avg;
            }

            if (node->left && node->right)
                avg = (leftFree.first + node->right->val) * 0.5;
            else if (node->left)
                avg = leftFree.first;
            else
                avg = node->right->val;

            changes = leftFree.second + rightFixed.second + (node->val == avg ? 0 : 1);
            if (changes < minChanges) {
                minChanges = changes;
                value = avg;
            }

            if (node->left && node->right)
                avg = (node->left->val + rightFree.first) * 0.5;
            else if (node->left)
                avg = node->left->val;
            else
                avg = rightFree.first;

            changes = leftFixed.second + rightFree.second + (node->val == avg ? 0 : 1);
            if (changes < minChanges) {
                changes = minChanges;
                value = avg;
            }
        } else {
            int leftVal;
            if (node->left && node->right)
                leftVal = node->val * 2 - node->right->val;
            else if (node->left)
                leftVal = node->val;

            if (node->left) {
                float temp = node->left->val;
                node->left->val = leftVal;
                auto leftFixed = dfs(node->left, true);
                auto rightFixed = dfs(node->right, true);
                changes = leftFixed.second + rightFixed.second + (leftVal == temp ? 0 : 1);
                if (changes < minChanges)
                    minChanges = changes;
                node->left->val = temp;
            }

            int rightVal;
            if (node->left && node->right)
                rightVal = node->val * 2 - node->left->val;
            else if (node->right)
                rightVal = node->val;

            if (node->right) {
                float temp = node->right->val;
                node->right->val = rightVal;
                auto leftFixed = dfs(node->left, true);
                auto rightFixed = dfs(node->right, true);
                changes = leftFixed.second + rightFixed.second + (rightVal == temp ? 0 : 1);
                minChanges = min(minChanges, changes);
                node->right->val = temp;
            }
            value = node->val;
        }
        return {value, minChanges};
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(0);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->left = new TreeNode(0);
    root->right->right->right->right = new TreeNode(1);
    root->right->right->right->right->left = new TreeNode(0);
    root->right->right->right->right->right = new TreeNode(1);
    assert(sol.makeBinaryTreeAverage(root) == 5);
    delete (root->right->right->right->right->right);
    delete (root->right->right->right->right->left);
    delete (root->right->right->right->right);
    delete (root->right->right->right->left);
    delete (root->right->right->right);
    delete (root->right->right->left);
    delete (root->right->right);
    delete (root->right->left);
    delete (root->right);
    delete (root->left);
    delete (root);
    return 0;
}

