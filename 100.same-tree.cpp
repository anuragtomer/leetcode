#include <iostream>
#include <queue>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
   public:
    /* Iterative */
    /*
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q2.empty() && !q1.empty()) {
            auto curr1 = q1.front();
            auto curr2 = q2.front();
            q1.pop();
            q2.pop();
            if (curr1 == nullptr && curr2 != nullptr)
                return false;
            if (curr2 == nullptr && curr1 != nullptr)
                return false;
            if (curr1->val != curr2->val)
                return false;
            if (curr1 != nullptr) {
                q1.push(curr1->left);
                q1.push(curr1->right);
            }
            if (curr2 != nullptr) {
                q2.push(curr2->left);
                q2.push(curr2->right);
            }
        }
        return true;
    }*/
    /* Recursive */
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;
        if (p == nullptr && q == nullptr)
            return true;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution sol;
    TreeNode *p = createTree("1,2,3", ',');
    TreeNode *q = createTree("1,2,3", ',');
    assert(true == sol.isSameTree(p, q));
    deleteTree(p);
    deleteTree(q);
    p = createTree("1,2", ',');
    q = createTree("1,null,2", ',');
    assert(false == sol.isSameTree(p, q));
    deleteTree(p);
    deleteTree(q);
    return 0;
}
