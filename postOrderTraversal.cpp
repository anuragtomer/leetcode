#include "lib.h"

using namespace std;

class Solution {
public:
/*
   // Recursive Approach:
        void postorderRecursive(TreeNode * root, vector<int> &res) {
            if (root) {
                postorderRecursive(root->left, res);
                postorderRecursive(root->right, res);
                res.push_back(root->val);
            }
        }
        vector<int> postorderTraversal(TreeNode * root) {
            vector<int> res;
            res.clear();
            postorderRecursive(root, res);
            return res;
        }
 */
 /*
 Two Stack solution:
vector<int> postorderTwoStack(TreeNode * root) {
    vector<TreeNode *> stack1;
    vector<int> res;
    res.clear();
    vector<int> output;
    output.clear();
    stack1.push_back(root);
    while(!stack1.empty()) {
        TreeNode * temp = stack1.back();
        stack1.pop_back();
        if (temp) {
            res.push_back(temp->val);
            stack1.push_back(temp->left);
            stack1.push_back(temp->right);
        }
    }
    while(res.size()) {
        output.push_back(res.back());
        res.pop_back();
    }
    return output;
}

vector<int> postorderTraversal(TreeNode *root) {
    return postorderTwoStack(root);
}
*/
vector<int> postorderOneStack(TreeNode * root) {
    stack<TreeNode *> st;
    vector<int> res;
    res.clear();
    do {
        while(root) {
            st.push(root->right);
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (root && !st.empty() && root->right && root->right == st.top()) {
            TreeNode * temp = st.top();
            st.pop();
            st.push(root);
            root= temp;
        } else {
            if (root)
                res.push_back(root->val);
            root = NULL;
        }
    }while(!st.empty());
    return res;
}
vector <int> postorderTraversal(TreeNode *root) {
    return postorderOneStack(root);
}
};

int main() {
	Solution sol;
	TreeNode * root;
	root = createTree();
	vector<int> result;
	result.clear();
	result = sol.postorderTraversal(root);
	for (int i: result) {
		cout << i << " ";
	}
	return 0;
}
