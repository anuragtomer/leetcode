#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxIndex(const vector<int> &nums, int lb, int ub) {
        int index = lb;
        for (int i = lb; i <= ub; ++i) {
            if (nums[index] < nums[i]) {
                index = i;
            }
        }
        return index;
    }
    
    TreeNode* constructMBT(vector<int> &nums, int lb, int ub) {
        TreeNode * root = nullptr;
        if (lb > ub)
            return root;
        else if (lb == ub) {
            root = new TreeNode(nums[lb]);
        } else {
            int maxElemIndex = maxIndex(nums, lb, ub);
            root = new TreeNode(nums[maxElemIndex]);
            root->left  = constructMBT(nums, lb, maxElemIndex-1);
            root->right = constructMBT(nums, maxElemIndex+1, ub);
        }
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode * root = nullptr;
        if (nums.size() == 0)
            return root;        
        else if (nums.size() == 1)
            root = new TreeNode(nums[0]);
        else {
            int maxElemIndex = maxIndex(nums, 0, nums.size() - 1);
            root = new TreeNode(nums[maxElemIndex]);
            root->left  = constructMBT(nums, 0, maxElemIndex-1);
            root->right = constructMBT(nums, maxElemIndex+1, nums.size() - 1);
        }
         return root;
    }
};
void
inorder(TreeNode * root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void
preorder(TreeNode * root) {
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(void) {
    vector<int> nums = {3,2,1,6,0,5};
    Solution sol;
    TreeNode * root = sol.constructMaximumBinaryTree(nums);
    cout << "\nInorder: \n";
    inorder(root);
    cout << "\nPreorder: \n";
    preorder(root);
    return 0;
}