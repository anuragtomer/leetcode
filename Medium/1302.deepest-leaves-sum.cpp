
#include "../include/utility.h"
using namespace std;

class Solution {
    void deepestLeavesSum(TreeNode *root, int level, map<int, int> &levelsum) {
        if (!root)
            return;
        if (level >= levelsum.rbegin()->first) {
            levelsum[level] += root->val;
        }
        if (root->left)
            deepestLeavesSum(root->left, level + 1, levelsum);
        if (root->right)
            deepestLeavesSum(root->right, level + 1, levelsum);
    }

   public:
    /* One way of doing this.
    int deepestLeavesSum(TreeNode *root) {
        int sum = 0;
        list<TreeNode *> q1, q2, lastSwapped;
        q1.push_front(root);
        while (!q1.empty()) {
            TreeNode *curr = q1.back();
            q1.pop_back();
            if (curr->left)
                q2.push_front(curr->left);
            if (curr->right)
                q2.push_front(curr->right);
            if (q1.empty() && !q2.empty()) {
                lastSwapped = q2;
                q1.swap(q2);
                q2.clear();
            }
        }

        for (auto q : lastSwapped)
            sum += q->val;
        return sum;
    } */
    // Another way of doing the same things.
    int deepestLeavesSum(TreeNode *root) {
        if (!root)
            return 0;
        map<int, int> levelsum;
        levelsum[-1] = 0;
        deepestLeavesSum(root, 0, levelsum);
        return levelsum.rbegin()->second;
    }
};

int main() {
    Solution sol;
    string input = "1,2,3,4,5,null,6,7,null,null,null,null,8";
    TreeNode *root = createTree(input, ',');
    assert(15 == sol.deepestLeavesSum(root));
    deleteTree(root);
    input = "1,2,3,4,5,null,6,null,null,null,null,null,8";
    root = createTree(input, ',');
    assert(8 == sol.deepestLeavesSum(root));
    deleteTree(root);
    input = "1,2,3,4,null,null,6";
    root = createTree(input, ',');
    assert(10 == sol.deepestLeavesSum(root));
    return 0;
}
