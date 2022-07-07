#include <iostream>
using namespace std;

class Solution {
   public:
    string reformat(string s) {
        string digits, alphabets;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                digits += ch;
            } else if (ch >= 'a' && ch <= 'z') {
                alphabets += ch;
            }
        }
        cout << "Alphabets: " << alphabets << "\nDigits: " << digits << endl;
        int digitsize = digits.size();
        int alphasize = alphabets.size();
        if ((digitsize - alphasize > 1) || (alphasize - digitsize > 1))
            return "";
        string newS;
        newS.resize(digitsize + alphasize);
        if (digitsize > alphasize) {
            int j = 0;
            for (int i = 0; i < digitsize; i++, j += 2)
                newS[j] = digits[i];
            j = 1;
            for (int i = 0; i < alphasize; i++, j += 2)
                newS[j] = alphabets[i];
            return newS;
        } else {
            int j = 0;
            for (int i = 0; i < alphasize; i++, j += 2)
                newS[j] = alphabets[i];
            j = 1;
            for (int i = 0; i < digitsize; i++, j += 2)
                newS[j] = digits[i];
            return newS;
        }
        return "";
    }
};

int main() {
    Solution sol;
    cout << sol.reformat("a0b1c2") << endl;
    cout << sol.reformat("leetcode") << endl;
    cout << sol.reformat("12345678") << endl;
    cout << sol.reformat("covid2019") << endl;
    cout << sol.reformat("ncov20192") << endl;
    return 0;
}