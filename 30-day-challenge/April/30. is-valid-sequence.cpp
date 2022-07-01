#include <iostream>
#include <queue>
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
    TreeNode *right = new TreeNode(0);
    TreeNode *left = new TreeNode(0);
    TreeNode *rootRight = new TreeNode(1, left, right);
    right = new TreeNode(1);
    TreeNode *rootLeft = new TreeNode(0, nullptr, right);
    TreeNode *root = new TreeNode(1, rootLeft, rootRight);
    left = new TreeNode(0);
    rootRight = new TreeNode(0, left, nullptr);
    rootLeft = root;
    root = new TreeNode(0, rootLeft, rootRight);
    /*      0
          /   \
         1     0
        / \    /\
       0   1  0  n
      /\  / \
     n  1 0  0
    */
    // Test case 1:
    vector<int> arr = {0, 1, 0, 1};
    assert(true == sol.isValidSequence(root, arr));
    cout << "Test case 1 passed.\n";
    // Test case 2:
    arr = {0, 0, 1};
    assert(false == sol.isValidSequence(root, arr));
    cout << "Test case 2 passed.\n";
    // Test case 3:
    arr = {0, 1, 1};
    assert(false == sol.isValidSequence(root, arr));
    cout << "Test case 3 passed.\n";
    queue<TreeNode *> q;
    q.push(root);
    while (q.empty() == false) {
        TreeNode *temp = q.front();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        q.pop();
        delete temp;
    }
    return 0;
}
