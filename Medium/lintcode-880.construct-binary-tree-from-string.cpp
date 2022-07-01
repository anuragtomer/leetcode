#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    TreeNode *str2tree(string &s) {
        int n = s.size();
        if (n == 0)
            return nullptr;
        string beg;
        int i = 0;
        for (; i < n && s[i] != '('; ++i) {
            beg.push_back(s[i]);
        }
        TreeNode *root = new TreeNode(atoi(beg.c_str()));
        ++i;
        string leftString, rightString;
        int open = 1;
        for (; i < n && open > 0; ++i) {
            leftString.push_back(s[i]);
            if (s[i] == '(')
                open++;
            if (s[i] == ')')
                open--;
        }

        if (!leftString.empty()) {
            if (leftString.back() == ')')
                leftString.pop_back();
            root->left = str2tree(leftString);
        }
        i++;
        open = 1;
        for (; i < n && open > 0; ++i) {
            rightString.push_back(s[i]);
            if (s[i] == '(')
                open++;
            if (s[i] == ')')
                open--;
        }
        if (!rightString.empty()) {
            if (rightString.back() == ')')
                rightString.pop_back();
            root->right = str2tree(rightString);
        }
        return root;
    }
};

int main() {
    Solution sol;

    return 0;
}

