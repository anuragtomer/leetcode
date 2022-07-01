#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution{
    public:
#if 0
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tsl;
        TreeNode *current_node;
        tsl.clear();
        stack<TreeNode *> stk;
        if (root)
            stk.push(root);
        current_node = root;
        while(!stk.empty() && current_node) {
            if (current_node->left) {
                stk.push(current_node->left);
            } else {
                tsl.push_back(current_node->val);
                stk.pop();
                if (current_node->right) {
                    stk.push(current_node->right);
                }
            }
            current_node = stk.top();
        }
        return tsl;
    }
#endif
#if 0
    Recursive:
    void inorder(TreeNode * root, vector<int> &tsl) {
        if (root) {
            inorder(root->left, tsl);
            tsl.push_back(root->val);
            inorder(root->right, tsl);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tsl;
        tsl.clear();
        if (root)
            inorder(root, tsl);
        return tsl;
    }
#endif
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        std::vector<int> res;
        res.clear();
        TreeNode* temp = root;
        while(temp || !st.empty()) {
            if (!temp) {
                temp = st.top()->right;
                res.push_back(st.top()->val);
                st.pop();
            }
            if (temp) {
                while(temp->left) {
                    st.push(temp);
                    temp = temp->left;
                }
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
        return res;
    }
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
    result = sol.inorderTraversal(root);
    for (auto &i: result)
        cout << i << " ";
    return 0;
}
