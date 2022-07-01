#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
    int divide(vector<int> &nums, int beg, int end, int target) {
        for (int i = beg; i <= end; i++) {
            if (nums[i] > target)
                return i;
        }
        return end + 1;
    }
    TreeNode *createTree(vector<int> &preorder, int beg, int end) {
        // cout << "Creating tree from " << beg << " to " << end << endl;
        if (beg < end) {
            int pivot = divide(preorder, beg + 1, end, preorder[beg]);
            TreeNode *root = new TreeNode(preorder[beg]);
            root->left = createTree(preorder, beg + 1, pivot - 1);
            root->right = createTree(preorder, pivot, end);
            return root;
        }
        if (beg == end) {
            return new TreeNode(preorder[beg]);
        }
        return nullptr;
    }

   public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return createTree(preorder, 0, preorder.size() - 1);
    }
};

void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *front = q.front();
        if (front == nullptr)
            cout << "null ";
        else
            cout << front->val << " ";
        q.pop();
        if (front && (front->left != nullptr || front->right != nullptr)) {
            q.push(front->left);
            q.push(front->right);
        }
    }
}

int main() {
    Solution sol;
    vector<int> nums = {8, 5, 1, 7, 10, 12};
    printTree(sol.bstFromPreorder(nums));
    cout << "\n";
    nums = {4, 2};
    printTree(sol.bstFromPreorder(nums));
    return 0;
}