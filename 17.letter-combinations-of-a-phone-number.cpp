/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void lettersRecursive(vector<string> digitToSet, unsigned int DTSindex, string str, vector<string> &output) {
        if (DTSindex == digitToSet.size()) {
            // We have added chars from each group. 
            output.push_back(str);
            return;
        } else {
            for (unsigned int j = 0; j < digitToSet[DTSindex].size(); j++) {
                str.push_back(digitToSet[DTSindex][j]);
                lettersRecursive(digitToSet, DTSindex+1, str, output);
                str.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        vector<string> digitToSet;
        for (unsigned int i = 0; i < digits.size(); i++) {
            switch(digits[i]) {
                case '2':
                    digitToSet.push_back("abc");
                    break;
                case '3':
                    digitToSet.push_back("def");
                    break;
                case '4':
                    digitToSet.push_back("ghi");
                    break;
                case '5':
                    digitToSet.push_back("jkl");
                    break;
                case '6':
                    digitToSet.push_back("mno");
                    break;
                case '7':
                    digitToSet.push_back("pqrs");
                    break;
                case '8':
                    digitToSet.push_back("tuv");
                    break;
                case '9':
                    digitToSet.push_back("wxyz");
                    break;
            }
        }
        vector<string> output;
        string str;
        lettersRecursive(digitToSet, 0, str, output);
        return output;
    }
};
// @lc code=end

int main() {
    string digits;
    cin >> digits;
    Solution sol;
    vector<string> output = sol.letterCombinations(digits);
    for (auto str: output)
        cout << str << "\t";
    return 0;
}