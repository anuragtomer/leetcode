#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        void largestValuesHash(TreeNode * root, map <int, int> &hash, int level) {
            if (root) {
                map <int, int> :: iterator got = hash.find(level);
                if (got == hash.end()) {
                    hash.insert({level, root->val});
                } else {
                    got->second = (got->second < root->val) ? root->val : got->second;
                }
                level++;
                largestValuesHash(root->left, hash, level);
                largestValuesHash(root->right, hash, level);
            }
        }
        
        vector<int> largestValues(TreeNode* root) {
            map <int, int> hash;
            vector<int> res;
            res.clear();
            // hash.insert({0, root->val});
            largestValuesHash(root, hash, 0);
            for (auto &i: hash) {
                res.push_back(i.second);
            }

            return res;
        }
        
        void preorderTraversal(TreeNode * root) {
            if (root) {
                cout << root->val << " ";
                preorderTraversal(root->left);
                preorderTraversal(root->right);
            }
        }
        
        void inorderTraversal(TreeNode * root) {
            if (root) {
                inorderTraversal(root->left);
                cout << root->val << " ";
                inorderTraversal(root->right);
            }
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
        x = x + 2;
    }
    vector<int> result;
    result.clear();
    result = sol.largestValues(root);
    for (auto &i: result) {
        cout << i << " ";
    }
    return 0;
}

#if 0
Original code:
Same logic, different data structure:
class Solution {
public:
    void findMax(TreeNode * root, int level, vector <int> & largest) {
        if (root == NULL)
            return;
        level = level + 1;
        if (largest.size() <= level + 1)
            largest.resize(level+1, INT_MIN);
        // cout << largest.size() <<" " << level <<endl;
        if (largest[level] < root->val)
            largest[level] = root->val;
        if (root->left == NULL && root->right == NULL){
            return;
        }
        if (root->left)
            findMax(root->left, level, largest);
        if (root->right)
            findMax(root->right, level, largest);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;
        largest.empty();
        if (root == NULL) {
            return {};
        }
        largest.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            return largest;
        }
        int level = 0;
        if (root->left)
            findMax(root->left, level, largest);
        if (root->right)
            findMax(root->right, level, largest);
        return largest;
    }
};
#endif

