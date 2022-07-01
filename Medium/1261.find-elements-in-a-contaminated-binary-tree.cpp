#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include "../include/utility.h"
using namespace std;

/*
class FindElements {
    TreeNode *tree;

   public:
    FindElements(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            if (top->left) {
                top->left->val = 2 * top->val + 1;
                q.push(top->left);
            }
            if (top->right) {
                top->right->val = 2 * top->val + 2;
                q.push(top->right);
            }
        }
        tree = root;
    }

    bool find(int target) {
        queue<TreeNode *> q;
        q.push(tree);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top->val == target)
                return true;
            if (top->val > target)
                return false;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        return false;
    }
};*/
class FindElements {
    set<int> values;

   public:
    FindElements(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            values.insert(top->val);
            if (top->left) {
                top->left->val = 2 * top->val + 1;
                q.push(top->left);
            }
            if (top->right) {
                top->right->val = 2 * top->val + 2;
                q.push(top->right);
            }
        }
    }

    bool find(int target) {
        return values.count(target);
    }
};

int main() {
    // Testcase 1:
    string tree = "-1,null,-1";
    TreeNode *root = createTree(tree, ',');
    FindElements obj = FindElements(root);
    int target = 1;
    assert(obj.find(target) == false);
    target = 2;
    assert(obj.find(target) == true);
    deleteTree(root);

    // Testcase 2:
    tree = "-1,-1,-1,-1,-1";
    root = createTree(tree, ',');
    obj = FindElements(root);
    target = 1;
    assert(obj.find(target) == true);
    target = 3;
    assert(obj.find(target) == true);
    target = 5;
    assert(obj.find(target) == false);
    deleteTree(root);

    // Testcase 3:
    tree = "-1,null,-1,-1,null,-1";
    root = createTree(tree, ',');
    obj = FindElements(root);
    target = 2;
    assert(obj.find(target) == true);
    target = 3;
    assert(obj.find(target) == false);
    target = 4;
    assert(obj.find(target) == false);
    target = 5;
    assert(obj.find(target) == true);
    deleteTree(root);
    return 0;
}
