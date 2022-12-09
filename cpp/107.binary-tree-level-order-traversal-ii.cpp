#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> temp;
        queue<TreeNode *> q1, q2;
        q1.push(root);
        vector<int> current;
        while (!q1.empty()) {
            auto tp = q1.front();
            current.push_back(tp->val);
            q1.pop();
            if (tp->left)
                q2.push(tp->left);
            if (tp->right)
                q2.push(tp->right);
            if (q1.empty()) {
                temp.push_back(current);
                current.clear();
                q1 = q2;
                q2 = queue<TreeNode *>();
            }
        }
        return vector<vector<int>>(temp.rbegin(), temp.rend());
    }
};

int main() {
    Solution sol;
    string input = "3,9,20,null,null,15,7";
    TreeNode *root = createTree(input, ',');
    vector<vector<int>> result, expected = {{15, 7}, {9, 20}, {3}};
    result = sol.levelOrderBottom(root);
    assert(testDoubleVector(result, expected) == true);
    return 0;
}
