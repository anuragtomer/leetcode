/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* #include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 */
class Solution {
public:
    TreeNode * ArraytoBST(vector<int> &nums, int beg, int end) {
        TreeNode * root = nullptr;
        if (beg <= end) {
            int mid = beg + (end - beg + 1) / 2;
            root = new TreeNode(nums[mid]);
            if (beg <= mid)
                root->left = ArraytoBST(nums, beg, mid - 1);
            if (mid <= end)
                root->right = ArraytoBST(nums, mid + 1, end);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = nullptr;
        if (nums.size() > 0) {
            int beg = 0;
            int end = nums.size() - 1;
            int mid = beg + (end - beg + 1)/2 ;
            root = new TreeNode(nums[mid]);
            if (mid > beg)
                root->left = ArraytoBST(nums, beg, mid - 1);
            if (mid < end)
                root->right = ArraytoBST(nums, mid + 1, end);
        }
        return root;            
    }
};


// @lc code=end
/* 
void printinorder(TreeNode * root) {
    if (root) {
        printinorder(root->left);
        cout << root->val << " ";
        printinorder(root->right);
    }
}

void printpreorder(TreeNode * root) {
    if (root) {
        cout << root->val << " ";
        printpreorder(root->left);
        printpreorder(root->right);
    }
}
void deletetree(TreeNode * root) {
    if (root) {
        deletetree(root->right);
        deletetree(root->left);
        delete root;
    }
}
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    TreeNode * root = sol.sortedArrayToBST(nums);
    printinorder(root);
    cout << "\n";
    printpreorder(root);
    deletetree(root);
    return 0;
} */