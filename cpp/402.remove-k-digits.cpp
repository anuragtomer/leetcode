#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    string removeKdigits(string num, int k) {
        // Base cases
        if (num.size() <= k)
            // Not enough digits.
            return "0";
        if (k == 0)
            // Nothing to be removed.
            return num;

        string stackOfDigits;
        for (char ch : num) {
            // Push element in stack such that stack has decreasing elements.
            while (k && !stackOfDigits.empty() && ch < stackOfDigits.back()) {
                k--;
                stackOfDigits.pop_back();
            }
            if (!stackOfDigits.empty())
                stackOfDigits.push_back(ch);
            else if (ch != '0')
                stackOfDigits.push_back(ch);
        }
        while (k && !stackOfDigits.empty()) {
            stackOfDigits.pop_back();
            k--;
        }
        // Check if num consists of only zeros.
        bool allZeros = true;
        for (auto ch : stackOfDigits)
            if (ch != '0') {
                allZeros = false;
                break;
            }
        return (stackOfDigits.empty() || allZeros) ? "0" : stackOfDigits;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;
    assert("1219" == sol.removeKdigits(num, k));
    num = "10200", k = 1;
    assert("200" == sol.removeKdigits(num, k));
    num = "10", k = 2;
    assert("0" == sol.removeKdigits(num, k));
    return 0;
}

