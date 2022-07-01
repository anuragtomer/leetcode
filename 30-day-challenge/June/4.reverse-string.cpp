#include <iostream>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {
   public:
    void reverseString(vector<char> &s) {
        reverse(s.begin(), s.end());
    };
};

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
    sol.reverseString(s);
    testResp(s, expected);
    s = {'H', 'a', 'n', 'n', 'a', 'h'};
    expected = {'h', 'a', 'n', 'n', 'a', 'H'};
    sol.reverseString(s);
    testResp(s, expected);
    return 0;
}
