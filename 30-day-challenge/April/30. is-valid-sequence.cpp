#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
   public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        if (!root || arr.empty())
            return false;
        if (root->val == arr[0])
            if (root->left == nullptr && root->right == nullptr && arr.size() == 1)
                return true;
            else {
                vector<int> nextarr(arr.begin() + 1, arr.end());
                return isValidSequence(root->left, nextarr) || isValidSequence(root->right, nextarr);
            }
        else
            return false;
    }
};

int main() {
    Solution sol;
    /*
    root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
    Output: true

    Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
    Output: false

    root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
    Output: false
    */
    return 0;
}
