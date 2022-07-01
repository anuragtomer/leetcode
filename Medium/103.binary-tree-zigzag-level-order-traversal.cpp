#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root)
            return vector<vector<int>>();
        vector<TreeNode *> level = {root};
        vector<vector<int>> result;
        bool rev = false;
        int i = 0;
        while (i < level.size()) {
            int n = level.size();
            vector<int> row;
            while (i < n) {
                row.push_back(level[i]->val);
                if (level[i]->left)
                    level.push_back(level[i]->left);
                if (level[i]->right)
                    level.push_back(level[i]->right);
                ++i;
            }
            if (!row.empty()) {
                if (rev) {
                    reverse(row.begin(), row.end());
                    result.push_back(row);
                } else {
                    result.push_back(row);
                }
                rev = !rev;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

