#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string s;

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = s + char(c % 2 + '0');
            c /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.addBinary("11", "1");
    return 0;
}

