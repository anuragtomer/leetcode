#include "lib.h"
#include <cmath>

class Solution {
public:
    #if 0
    void noTillLeaf(TreeNode * root vector <int> &arr int num) {
        if (root) {
            num = (num << 1) + root->val;
            if (!root->left && !root->right) {
                arr.push_back(num);
            } else {
                if (root->left)
                    noTillLeaf(root->left arr num);
                if (root->right)
                    noTillLeaf(root->right arr num);
            }
        }
    }
    int sumRootToLeaf(TreeNode * root) {
        vector <int> arr;
        arr.clear();
        noTillLeaf(root arr  0);
        int sum = 0;
        for (int i: arr)
            sum += i;
        return sum;
    }
    #endif
    void noTillLeaf(TreeNode * root,  vector <int> &arr,  long long int num) {
        if (root) {
            num = ((num * 2) + root->val) % 1000000007;
            if (!root->left && !root->right) {
                arr.push_back(num);
            } else {
                if (root->left)
                    noTillLeaf(root->left,  arr,  num);
                if (root->right)
                    noTillLeaf(root->right,  arr,  num);
            }
        }
    }
    int sumRootToLeaf(TreeNode * root) {
        vector <int> arr;
        arr.clear();
        noTillLeaf(root, arr,  0);
        int sum = 0;
        for (int i: arr)
            sum = ((sum + i) % 1000000007);
        return sum;
    }
};

int main(){
    Solution sol;
    TreeNode * root = createTree();
    cout << sol.sumRootToLeaf(root);
    return 0;
}



/*
 *  [1 1 1 0 null 1 null 1 null 0 null 1 null 0 null 0 null 0 null 1 null 0 null 0 null 1 null 0 null 0 null 1 null 0 1 0 null 1 null 1 null 0 null 0 null 1 null 1 null 0 null 0 1 0 null 1 null 0 null 1 1 1 0 0 null 0 null 1 1 0 null 1 0 1 null 1 null 1 null 0 null 1 null 0 null 0 null 0 null 1 null 0 null 1 0 0 null 0 1 1 1 0 null 1 null 0 null 0 null 0 1 0 null 0 null 1 null 1 null 0 null 0 null 0 null 0 null 0 null 0 0 1 null 1 null 1 null 0 null 0 0 1 null 0 1 1 null 1 null 1 null 0 1 0 null 0 null 0 1 1 1 0 1 1 null 1 null 0 1 1 0 1 null 0 null 1 1 1 null 0 null 1 null 0 null 0 null 1 null 1 null 0 null 1 null 1 1 1 null 1 null 1 0 1 1 1 null 1 0 0 null 0 1 0 null 1 null 0 null 1 null 1 null null 1 1 null 0 null 1 1 0 null 1 0 1 null 0 null 0 null 1 null 1 0 1 0 1 null 0 null 1 1 0 0 0 null 1 null 1 null 1 null 1 null 1 null 0 null 0 null 1 null 0 null 1 null null 1 0 null 1 null 0 null 0 null 0 null 1 1 1 null 1 null 1 null 1 null 1 null 1 null 0 null 1 null 1 null 1 null 1 0 0 null 0 0 1 1 1 0 0 null null 0 null null 1 null 0 null 0 null 1 null 1 0 1 null 1 null 1 null null null null 0 1 1 0 0 1 1 1 null null 1 1 0 0 null 0 null 0 null 1 null 0 0 0 null 0 0 0 null 1 null 0 1 1 1 0 1 1 null 0 null 1 null 1 null 1 0 1 null 0 1 0 null 0 null 0 1 1 null 0 0 0 null 0 null 0 null 0 null 0 null 0 1 0 null 0 null null 0 1 null 0 0 0 null null null null 0 0 null 0 null null null null null 0 1 0 0 null null 0 1 1 null 0 0 1 null 0 null 1 0 1 null 1 null 0 1 0 null 1 null 0 null 0 1 0 null 0 null 0 null null null null 0 1 0 1 0 0 0 0 null 1 null 1 0 null null 0 1 null null 1 null 0 null 1 null 0 null 1 0 1 null 1 null 1 null 0 null null null null null null null null null null 1 0 null null null null null null null 0 null 0 null 0 null null null 0 1 0 null 1 1 0 null 1 null 1 1 0 null 0 1 0 1 1 null null null 1 null 1 null 1 0 0 1 0 null 0 0 1 1 0 null null null 0 null 1 null 1 0 1 null 1 0 1 null null null 0 null null null 0 null null null 0 0 1 0 1 null 1 null 1 null 0 null 1 null 1 1 0 null 0 null 0 null 1 null 1 null 0 null null null null null 0 null 0 null 1 null 1 null 0 null 1 null 1 null null null 0 null 1 null 0 null 0 null 1 null 0 null 0 null 0 null 0 1 1 1 1 null 1 null 1 0 0 1 1 null 0 0 1 null 1 0 1 null 0 null 1 null 0 null 1 null 1 null 1 null 1 null null null 0 null 1 null null 1 0 null 1 1 null null null null null null 0 null 1 null null null 0 null 1 null 1 null 0 null 1 null 0 null 0 0 0 null 0 1 0 null 1 null null null 0 null 1 0 null null 0 0 0 null null null 0 null 1 null 0 0 0 null 1 null 1 null 0 null 0 null 1 null 0 null 1 null 1 0 0 null 1 1 1 null 1 null 1 null 0 null 0 0 1 1 1 0 0 1 0 null 1 1 0 null 0 null 1 null 0 null 1 null null null 0 null null null 0 null 0 null 1 null null null 1 0 0 null 1 null null null 0 null 1 null 1 0 null null 1 0 1 null 0 null 0 0 0 null null null null null 0 null 1 null 1 null 1 null 0 0 null null 1 1 0 null null null 0 null 0 null 0 null 0 0 null null null null 1 null 0 null 0 1 0 null 0 0 1 null 0 null 1 null 1 null 1 null 1 null 0 null 0 1 0 null 0 1 1 null 1 null 0 null 1 null 1 null 0 null 0 null 1 1 1 null 0 0 null null 0 1 1 null 0 null null null null null 1 0 1 null null null null null null null 0 null 1 1 null null null null 1 1 0 null 0 null 0 1 1 0 0 null 1 1 0 0 1 null 0 null 1 0 null null null null 0 0 1 null 1 null null 0 null null 1 1 0 1 1 null null null null null 0 null 1 null 0 null null null 0 null null null 0 1 null null null null 0 null 1 null 1 null 1 null 0 0 0 0 1 null 1 null 0 null 1 null 1 null 0 1 1 0 1 0 1 null 0 null 0 null 0 null 0 0 0 null 0 null 0 1 0 null 0 null 0 null 0 null 0 1 0 null null 1 null 1 0 null null null 1 null 0 1 0 null 0 null 0 0 1 null 1 null 0 null 1 1 0 null 1 null 1 null 1 null 0 null null null null null null null 0 null null null null null null null null null null null null null null null null null null null null null null null 1 null null null null null null null 0 null 1 0 1 null 0 0 1 0 0 null 0 0 0 0 1 null 1 null 0 null 1 null 1 null 1 0 1 null 0 null 1 null 0 null 0 1 null null 0 1 1 null 0 null 1 null null null 1 1 0 null 1 null 0 null 1 null 1 null 0 1 0 null null 0 null null 0 null 1 0 null null null null 0 null null 1 null null 0 null 0 null 1 null 1 null 0 null 0 null 1 null 0 null 0 null null null null null 0 1 0 null null null 1 null 0 null 1 null 0 null 1 null 1 0 1 null 1 0 null null 0 null 0 null 0 null 0 null 1 null 1 1 0 null 0 null 1 1 0 null 0 null 0 null 1 null 1 null 1 0 0 null 1 null 1 null 1 1 1 null 1 null 1 null 0 null null null null null 0 null 1 null 0 1 1 0 0 null null null 1 0 0 0 0 null null null 0 null null null null null 0 null 0 null 0 null 1 null 1 null null null 0 null 0 1 null null 0 null 0 null null null null null null null 1 null null null 1 null 1 null null null 0 null 0 null null null 0 0 0 null null null null null null null 1 null 0 null null null null null 0 null 0 null 0 null 0 0 1 null 0 null 1 null 1 0 0 null 0 null 1 null 1 null null null null null 0 null 1 null 1 null null null 0 0 null null null null 1 null 1 0 1 0 1 null 1 0 0 null 1 1 0 null 1 null 1 1 1 1 null 0 0 null null null 0 0 null null 1 null 0 null null null null null 1 null 0 null null null 1 null 1 null 0 null null null 0 null 0 null 1 null null null null null 1 null 1 null 0 1 0 null 0 null 1 null null null 0 null null null 1 null 1 null 1 1 1 1 0 null null null null null 1 null 1 null null null 0 null 1 1 0 null null null 0 1 1 1 0 null 1 null 0 null 1 null null 0 1 1 null null 0 null null null 0 null 1 null 0 1 0 1 null null 1 null 0 null 0 0 null null null null null null 0 1 0 1 1 null 0 0 1 0 null null 1 null null null 1 null 1 null 0 null 1 null 1 null null null 0 null null null null null null null 0 null 0 null null null null 0 null null 1 null null 0 0 null 0 1 null 1 0 1 0 null null 1 0 0 0 null 0 null null null 1 null 1 0 null null 0 null 1 1 1 null null null null null null null 0 null null null 1 null null null 0 null 0 null 0 null null null null null null null 1 null 0 null 1 null null null null null null null 1 null 1 null 1 0 1 0 1 null null null 0 null null null null null null null 0 null null 1 null null 1 null null null null null null null 1 null 1 null null null 1 1 0 null 1 0 null null 1 null 0 0 1 null 1 null null null null 1 null null 1 0 0 null null 0 1 null null null 0 null null null 1 1 1 null 0 null 1 1 1 null null 1 0 null null null null 0 1 null 1 0 null null null null 0 null 0 0 0 null null null 0 1 1 null 0 null null null null null 1 null null 1 null null 1 null null null null 1 null null 0 null 0 0 1 null null null null null 1 1 null null null null null null null null 0 0 null null 0 null null null null null 0 null 0 null 1 null 0 null 1 null 0 null null null null null null null null null null null 1 null null null null 0 null null 0 null 1 null null null null null 1 null 1 null 0 null null null 0 null 1 null 0 null null null null null null 0 null null null 1 null null 1 null null null null null 1 0]
 */
