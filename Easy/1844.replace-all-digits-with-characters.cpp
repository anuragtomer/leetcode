#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i += 2)
            s[i + 1] = s[i] + s[i + 1] - '0';
        return s;
    }
};

int main() {
    Solution sol;
    assert("abcdef" == sol.replaceDigits("a1c1e1"));
    return 0;
}

