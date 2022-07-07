#include "lib.h"
#include <climits>

class Solution {
public:
    void maxAncestorDiffRecursive(TreeNode * root, int &min, int &max) {
        int leftMin;
        int leftMax;
        int rightMin;
        int rightMax;
        if (!root)
            return;
        if (root->val < min) {
            leftMin = root->val;
        } else {
            leftMin = min;
        }
        if (root->val > max) {
            leftMax = root->val;
        } else {
            leftMax = max;
        }
        rightMin = leftMin;
        rightMax = leftMax;
        maxAncestorDiffRecursive(root->left, leftMin, leftMax);
        maxAncestorDiffRecursive(root->right, rightMin, rightMax);
        if ((leftMax - leftMin) < (rightMax - rightMin)) {
            min = rightMin;
            max = rightMax;
        } else {
            min = leftMin;
            max = leftMax;
        }
    }
    int maxAncestorDiff(TreeNode * root) {
        int min = root->val;
        int max = root->val;
        maxAncestorDiffRecursive(root, min, max);
        return (max - min);
    }
};

int main() {
    Solution sol;
    TreeNode * root = createTree();
    cout << sol.maxAncestorDiff(root);
    return 0;
}


/*
 * Input: [8 3 10 1 6 null 14 null null 4 7 13]
 * Output : 7
 *
 * Input : [1 null 2 null 0 3]
 * Output : 3
 *
 * Input: [0 null 1]
 * Output: 1
 *
 * Input: [5 0 null 2 null 4 null null 3 null 1]
 * Output: 5
 */
