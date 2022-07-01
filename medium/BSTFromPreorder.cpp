#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findMax(const vector<int> &nums, const int &val, int lb, int ub) {
        if (lb > ub) {
            return -2;
        } else {
            int i = lb;
            for (i = lb; i <= ub && nums[i] < val; ++i);
            return i;
        }
    }
    
    TreeNode * bstFromPreorderRecursive(const vector<int> & preorder, int lb, int ub) {
        if (lb < 0 || ub < 0 || lb > ub)
            return nullptr;
        TreeNode * root = new TreeNode(preorder[lb]);
        if (root == nullptr)
            return nullptr; // Check if memory was successfully allocated or not.
        if (lb == ub)
            return root;
        int maxElemIndex = findMax(preorder, preorder[lb], lb+1, ub);
        root->left = bstFromPreorderRecursive(preorder, lb+1, maxElemIndex-1);
        root->right = bstFromPreorderRecursive(preorder, maxElemIndex, ub);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorderRecursive(preorder, 0, preorder.size() - 1);
    }
};

void display(TreeNode * root) {
    if (root) {
        cout << root->val << " ";
    } else {
        return;
    }
    if (root->left) {
        cout << root->val << "->left: " << root->left->val << " ";
    }
    if (root->right) {
        cout << root->val << "->right: " << root->right->val << " " << endl;
    }
    cout << endl;
    display(root->left);
    display(root->right);
}
int main() {
    Solution sol;
    vector<int> preorder;
    preorder.clear();
    int noOfElements, element;
    cin >> noOfElements;
    while(noOfElements>0) {
        noOfElements--;
        cin >> element;
        preorder.push_back(element);
    }
    TreeNode * root = sol.bstFromPreorder(preorder);
    display(root);
    return 0;
}


