#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        void preorder(TreeNode * root, vector<int> &traversal) {
        if (root) {
            traversal.push_back(root->val);
            preorder(root->left, traversal);
            preorder(root->right, traversal);
        }        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traversal.clear();
        if (root) {
            preorder(root, traversal);
        }
        return traversal;
    }
    /* 
     * Iterative Approach
     *  
        vector<int> preorderTraversal(TreeNode * root) {
        stack<TreeNode *> st;
        vector<int> output;
        output.clear();
        if (root) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode * tp = st.top();
            st.pop();
            output.push_back(tp->val);            
            if (tp->right)
                st.push(tp->right);
            if (tp->left) 
                st.push(tp->left);
        }
        return output;
    }
    */
};
int main() {
    Solution sol;

    string input;
    getline(cin, input);
    stringstream s(input);
    string word;
    vector<TreeNode*> listOfNodes;
    listOfNodes.clear();
    while(s >> word) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(NULL);
        } else {
            int val = stoi(word);
            TreeNode * node = new TreeNode(val);
            listOfNodes.push_back(node);
        }
    }
    TreeNode * root = listOfNodes[0];
    TreeNode * node = root;
    for (int i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        node->right = listOfNodes[x+1];
        node = listOfNodes[i];
        while(!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    vector<int> result;
    result = sol.preorderTraversal(root);
    for (auto &i: result)
        cout << i << " ";
    return 0;
}


