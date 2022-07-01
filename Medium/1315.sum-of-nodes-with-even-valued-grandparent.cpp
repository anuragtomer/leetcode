#include "../include/utility.h"
using namespace std;

class Solution {
    /*
    One way of doing this.
     int sumup(TreeNode *root) {
        int sum = 0;
        if (root->left) {
            if (root->left->left)
                sum += root->left->left->val;
            if (root->left->right)
                sum += root->left->right->val;
        }
        if (root->right) {
            if (root->right->left)
                sum += root->right->left->val;
            if (root->right->right)
                sum += root->right->right->val;
        }
        return sum;
    }

   public:
    int sumEvenGrandparent(TreeNode *root) {
        if (!root)
            return 0;
        int sum = 0;
        if (root->val % 2 == 0)
            sum = sumup(root);
        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);
        return sum;
    } */
    // Another way: But slower and more memory consuming.
    void sumEvenGrandparent(TreeNode *root, list<int> level, int current, int &sum) {
        if (!root)
            return;
        if (!level.empty() && current == level.front()) {
            sum += root->val;
            level.pop_front();
        }
        if (root->val % 2 == 0)
            level.push_back(current + 2);
        sumEvenGrandparent(root->left, level, current + 1, sum);
        sumEvenGrandparent(root->right, level, current + 1, sum);
    }

   public:
    int sumEvenGrandparent(TreeNode *root) {
        if (!root)
            return 0;
        list<int> level;
        int sum = 0;
        sumEvenGrandparent(root, level, 0, sum);
        return sum;
    }
};

int main() {
    Solution sol;
    string input = "6,7,8,2,7,1,3,9,null,1,4,null,null,null,5";
    TreeNode *root = createTree(input, ',');
    assert(sol.sumEvenGrandparent(root) == 18);
    return 0;
}
