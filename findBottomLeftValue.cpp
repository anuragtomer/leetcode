#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
        void findBottom(TreeNode * root, int size, int &leftmost, int &level) {
            size++;
            if (size > level) {
                leftmost = root->val;
                level = size;
            }
            if (root->left) {
                findBottom(root->left, size, leftmost, level);
            } 
            if (root->right) {
                findBottom(root->right, size, leftmost, level);
            }
        }
        int findBottomLeftValue(TreeNode * root) {
            int leftmost = INT_MIN;
            int level = 0;
            int size = 0;
            if (root) {
                leftmost = root->val;
                if (root->left) {
                    findBottom(root->left, size, leftmost, level);
                } 
                if (root->right) {
                    findBottom(root->right, size, leftmost, level);
                }
                return leftmost;
            } else 
                return INT_MIN;
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
    int result;
    result = sol.findBottomLeftValue(root);
    cout << result;    
    return 0;
}

#if 0
Original solution faster. 
find bottommost level in left and right. If left deeper, return left value. If right deeper return right value.
class Solution {
public:
    int findbottom(TreeNode * root, int* level) {
        *level = *level + 1;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int value_left;
        int value_right;
        int level_left = *level;
        int level_right = *level;
        if (root->left) {
            value_left = findbottom(root->left, &level_left);
        }
        if (root->right) {
            value_right = findbottom(root->right, &level_right);
        }
        if (level_right > level_left) {
            *level = level_right;
            return value_right;
        }
        else {
            *level = level_left;
            return value_left;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int level_left = 0;
        int level_right = 0;
        int value_left;
        int value_right;
        if (root->left) {
            value_left = findbottom(root->left, &level_left);
        }
        if (root->right) {
            value_right = findbottom(root->right, &level_right);
        }
        if (level_right > level_left)
            return value_right;
        else
            return value_left;
    }
};
#endif
