#include <algorithm>
#include <iostream>
#include <queue>
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
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> currLevel, nextLevel;
        if (root != nullptr)
            currLevel.push(root);
        int currMax = INT_MIN;
        vector<int> result;
        while (!currLevel.empty()) {
            auto nextNode = currLevel.front();
            currLevel.pop();
            currMax = max(currMax, nextNode->val);
            if (nextNode->left)
                nextLevel.push(nextNode->left);
            if (nextNode->right)
                nextLevel.push(nextNode->right);
            if (currLevel.empty()) {
                result.push_back(currMax);
                currMax = INT_MIN;
                currLevel = nextLevel;
                nextLevel = queue<TreeNode *>();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

