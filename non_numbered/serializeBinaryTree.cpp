#include "lib.h"

class Solution{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        list<TreeNode *> que;
        string str;
        str.clear();
        que.clear();
        que.push_back(root);
        while(que.size() != 0) {
            root = que.front();
            que.pop_front();
            if (root) {
                que.push_back(root->left);
                que.push_back(root->right);
            }
            if (!root)
                if (str.size() == 0)
                    str = "null";
                else
                    str += ", null";
            else
                if (str.size() == 0)
                    str = to_string(root->val);
                else
                    str = str + ", " + to_string(root->val);
        }
        return str;
    }

    void clearSpaces(string &data) {
        int i = 0, j = 0;
        string newdata;
        newdata.clear();
        while(data[i] != '\0') {
            if (data[i] != ',' && data[i] != '[' && data[i] != ']') {
                newdata.append(1, data[i]);
                j++;
            }
            i++;
        }
        newdata.resize(j);
        data = newdata;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        clearSpaces(data);
        stringstream S(data);
        vector<TreeNode *> listOfNodes;
        listOfNodes.clear();
        string word;
        while(S >> word) {
            if (word.compare("null") == 0)
                listOfNodes.push_back(NULL);
            else {
                TreeNode * temp = new TreeNode(stoi(word));
                listOfNodes.push_back(temp);
            }
        }
        TreeNode * root = listOfNodes[0];
        TreeNode * temp = root;
        for (int i = 1, x = 1; x < listOfNodes.size();i++) {
            temp->left = listOfNodes[x];
            temp->right = listOfNodes[x+1];
            temp = listOfNodes[i];
            while (!temp)
            {
                temp = listOfNodes[++i];
            }
            x = x + 2;
        }
        return root;
    }
};

int main() {
    Solution sol;
    TreeNode * root = createTree();
    cout << "original: \n";
    printTree(root);
    cout << "\nNew tree:\n";
    TreeNode *newroot = sol.deserialize(sol.serialize(root));
    printTree(newroot);
	return 0;
}
