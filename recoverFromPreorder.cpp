#include "lib.h"
#include <cassert>

class Solution {
public:
    TreeNode * recoverFromPreorder(string S) {
        string level;
        level.clear();
        string number;
        number.clear();
        stack <TreeNode *> st;
        int currentLevel = -1;
        for (unsigned i = 0; i < S.size();) {
            int j = i;
            while(S[j] == '-' && j < S.size()) {
                level.append(1, S[j]);
                j++;
            }
            while (S[j] != '-' && j < S.size()) {
                number.append(1, S[j]);
                j++;
            }
            i = j;
            int num = stoi(number);
            int nextLevel = level.size();
            if (currentLevel < nextLevel) {
                TreeNode * temp = new TreeNode(num);
                if (st.size() > 0 && st.top()->left == NULL) {
                    st.top()->left = temp;
                } else if (st.size() > 0 && st.top()->right == NULL) {
                    st.top()->right = temp;
                }
                 /* cout << "Pushing " << num << " into stack." << endl; */
                st.push(temp);
                currentLevel++;
            } else if (currentLevel == nextLevel) {
                TreeNode * temp = new TreeNode(num);
                TreeNode * left = st.top();
                 /* cout << "Removing " << left->val << " from stack." << endl; */
                st.pop();

                assert(st.top()->right == NULL);
                 /* cout << "Setting " << st.top()->val << " node's right to " << temp->val << endl; */
                st.top()->right = temp;
                 /* cout << "Pushing " << temp->val << " into stack." << endl; */
                st.push(temp);
            } else {
                TreeNode * temp = new TreeNode(num);
                while(st.size() > nextLevel) {
                     /* cout << "Removing " << st.top()->val << " from stack." << endl; */
                    st.pop();
                }
                assert(st.top()->right == NULL);
                 /* cout << "Setting " << st.top()->val << " node's right to " << temp->val << endl; */
                st.top()->right = temp;
                 /* cout << "Pushing " << num << " into stack." << endl; */
                st.push(temp);
                currentLevel = nextLevel;
            }
            number.clear();
            level.clear();
        }
        while(st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string S;
    cin >> S;
    TreeNode * root = sol.recoverFromPreorder(S);
    printTree(root);
    return 0;
}
