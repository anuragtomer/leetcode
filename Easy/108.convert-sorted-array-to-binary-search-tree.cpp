#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    TreeNode *helper(vector<int> &num, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = helper(num, start, mid - 1);
        root->right = helper(num, mid + 1, end);
        return root;
    }

   public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty())
            return nullptr;
        return helper(nums, 0, nums.size() - 1);
    }
};
