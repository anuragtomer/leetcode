#include "lib.h"

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> Result;
        Result.clear();
        vector<TreeNode *> current;
        current.clear();
        current.push_back(root);
        vector<int> result;
        result.clear();
        vector<TreeNode *> next_vec;
        next_vec.clear();
        for (int i = 0; i < current.size(); i++) {
            if (current[i]->left) next_vec.push_back(current[i]->left);
            if (current[i]->right) next_vec.push_back(current[i]->right);
            if (i == current.size() - 1) {
                for (TreeNode * temp: current) {
                    result.push_back(temp->val);
                }
                Result.push_back(result);
                result.clear();
                current = next_vec;
                next_vec.clear();
                i = -1;
            }
        }
        return Result;
    }
};

int main(){
    Solution sol;
    TreeNode * root = createTree();
    vector<vector<int>> result;
    result = sol.levelOrder(root);
    for(vector<int> lower: result) {
        for (int i: lower) {
            cout << i << " ";
        }
    }
	return 0;
}
