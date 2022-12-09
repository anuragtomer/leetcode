#include <iostream>
#include <queue>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
   public:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        vector<TreeNode *> listOfNodes;
        listOfNodes.push_back(root);
        for (int i = 0; i < listOfNodes.size(); ++i) {
            auto current = listOfNodes[i];
            if (current->left)
                listOfNodes.push_back(current->left);
            if (current->right)
                listOfNodes.push_back(current->right);
        }
        return listOfNodes.size();
    }
};

int main() {
    Solution sol;
    string input = "1,2,3,4,5,6";
    TreeNode *root = createTree(input, ',');
    assert(6 == sol.countNodes(root));
    return 0;
}
