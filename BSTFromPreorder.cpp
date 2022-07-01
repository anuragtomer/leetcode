#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
/*    int nextGreaterIndex(vector <int> preorder, int val, int lb, int ub) {
        int i;
        for (i = lb; i < ub; i++) {
            if (val < preorder[i])
                return i;
        }
        return lb;
    }
    TreeNode * bstFromPreorderIndex(vector<int> & preorder, int lb, int ub) {
        if (lb > ub) {
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[lb]);
        if (lb+1 > ub) {
            root->left = NULL;
            root->right = NULL;
        }
        else {
            int idx = nextGreaterIndex(preorder, preorder[lb], lb+1, ub);
            root->left = bstFromPreorderIndex(preorder, lb+1, idx);
            root->right = bstFromPreorderIndex(preorder, idx+1, ub);
        }
        return root;
    }
*/
    int findMaxElementIndex(vector <int> preorder, int val, int lb, int ub) {
        for (int i = lb; i <= ub; i++) {
            if (val < preorder[i])
                return i;
        }
        return -1;
    }
    TreeNode * bstFromPreorderIndex(vector<int> & preorder, int lb, int ub) {
        if (ub < lb) {
            return NULL;
        } else {
            TreeNode *root = new TreeNode(preorder[lb]);
            int max_element_index = findMaxElementIndex(preorder, preorder[lb], lb+1, ub);
            if (max_element_index == -1) {
                root->left = bstFromPreorderIndex(preorder, lb+1, ub);
                root->right = NULL;
            } else if (max_element_index == lb+1) {
                root->left = NULL;
                root->right = bstFromPreorderIndex(preorder, lb+1, ub);
            } else {
                root->left = bstFromPreorderIndex(preorder, lb+1, max_element_index - 1);
                root->right = bstFromPreorderIndex(preorder, max_element_index, ub);
            }
            return root;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorderIndex(preorder, 0, preorder.size() - 1);
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


