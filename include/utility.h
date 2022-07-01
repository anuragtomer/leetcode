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

/**
 * Not yet refined. Might not work as expected.
 */
void printLevelTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == nullptr)
            cout << "\n";
        else {
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            q.push(nullptr);
        }
    }
}