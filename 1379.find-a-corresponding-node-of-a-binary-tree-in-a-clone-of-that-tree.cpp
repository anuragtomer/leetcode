#include "../include/utility.h"

using namespace std;

class Solution {
   public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == target)
            return cloned;
        if (!original)
            return nullptr;
        TreeNode *found = nullptr;
        if (original->left)
            found = getTargetCopy(original->left, cloned->left, target);
        if (!found)
            found = getTargetCopy(original->right, cloned->right, target);
        return found;
    }
};

int main() {
    Solution sol;

    // Test case 1:
    string input = "7,4,3,null,null,6,19";
    TreeNode *original = createTree(input, ',');
    TreeNode *cloned = createTree(input, ',');
    TreeNode *target = original->right;
    assert(cloned->right == sol.getTargetCopy(original, cloned, target));
    deleteTree(original);
    deleteTree(cloned);

    // Test case 2:
    input = "7";
    original = createTree(input, ',');
    cloned = createTree(input, ',');
    target = original;
    assert(cloned == sol.getTargetCopy(original, cloned, target));
    deleteTree(original);
    deleteTree(cloned);

    // Test case 3:
    input = "8,null,6,null,5,null,4,null,3,null,2,null,1";
    original = createTree(input, ',');
    cloned = createTree(input, ',');
    target = original->right->right->right;
    assert(cloned->right->right->right == sol.getTargetCopy(original, cloned, target));
    deleteTree(original);
    deleteTree(cloned);

    // Test case 4:
    input = "1,2,3,4,5,6,7,8,9,10";
    original = createTree(input, ',');
    cloned = createTree(input, ',');
    target = original->left->right;
    assert(cloned->left->right == sol.getTargetCopy(original, cloned, target));
    deleteTree(original);
    deleteTree(cloned);
    return 0;
}
