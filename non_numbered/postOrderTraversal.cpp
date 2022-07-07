#include "lib.h"

using namespace std;

class Solution {
public:
/*
   // Recursive Approach:
        void postorderRecursive(TreeNode * root, vector<int> &res) {
        // Go to left first, then go to right, once done with both children, print the root.
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
    // Idea is to keep root in stack2 while keeping left right children in stack1.
    // If we do so, we will have reverse of postorder in stack2. We shall then revert the stack2
    // and return result.
    stack<TreeNode *> stack1;
    stack<int> stack2;
    vector<int> output;
    output.clear();
    stack1.push(root);
    while(!stack1.empty()) {
        TreeNode * temp = stack1.top(); // Take out the current root.
        stack1.pop();
        if (temp) {
            // push the root's children in the first stack, root into the second stack.
            stack2.push(temp->val);
            stack1.push(temp->left);
            stack1.push(temp->right);
        }
    }
    while(!stack2.empty()) {
        output.push_back(stack2.top());
        stack2.pop();
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
        // Keep pushing right and then root until you are in the left corner of the tree headed by
        // root.
        while(root) {
            st.push(root->right);
            st.push(root);
            root = root->left;
        }
        // Now you are in the left corner of the tree headed by root. Pop an element from the stack.
        root = st.top();
        st.pop();
        // Now, we need to check if this root has been already processed. If this root is processed,
        // its right should not be there in the stack. If such is not the case, then we need to
        // process the right subtree first. So we push right subtree into the stack.
        if (root && !st.empty() && root->right && root->right == st.top()) {
            TreeNode * temp = st.top();
            st.pop();
            st.push(root);
            root= temp;
        } else {
            // We did not find root->right in the stack top. So, we have indeed processed both the
            // lower children for this root. Now we can push this root into result.
            // We set root = NULL to indicate we have processed tree rooted at this root. Pop new
            // element from stack next time for further processing.
            if (root)
                res.push_back(root->val);
            root = NULL;
        }
    } while(!st.empty());
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
