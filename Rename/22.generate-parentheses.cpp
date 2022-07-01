/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void generateRecursive(int ol, int cl, string str, vector<string> &output) {
        if (ol == 0 && cl == 0) {
            output.push_back(str);
            return;
        }

        if (ol > 0) {
            str.push_back('(');
            generateRecursive(ol-1, cl+1, str, output);
            str.pop_back();
        }
        if (cl > 0) {
            str.push_back(')');
            generateRecursive(ol, cl-1, str, output);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n <= 0)
            return {};
        string str;
        vector<string> output;
        generateRecursive(n, 0, str, output);
        return output;
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<string> parentheses = sol.generateParenthesis(n);
    for (auto &parenthesis : parentheses)
        cout << parenthesis << "\t";
    
    return 0;
}