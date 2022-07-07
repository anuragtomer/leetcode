#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int prod = carry + (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                carry = prod / 10;
                prod = prod % 10;
                result[i + j + 1] = ('0' + prod);
            }
            int tempi = i;
            while (carry > 0 && tempi >= 0) {
                carry = carry + result[tempi] - '0';
                result[tempi] = carry % 10 + '0';
                carry /= 10;
                --tempi;
            }
        }
        auto it = result.begin();
        while (it != result.end() && *it == '0')
            it = next(it);
        return (it == result.end()) ? "0" : string(it, result.end());
    }
};

int main() {
    Solution sol;

    assert("6" == sol.multiply("2", "3"));
    return 0;
}

