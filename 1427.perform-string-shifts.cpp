/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int length = 0;
        for (auto sft : shift)
            length += (sft[0] == 0) ? (-1 * sft[1]) : sft[1];

        if (length >= 0)
            length = length % s.size();
        else
            length = (-1) * ((-1 * length) % s.size());

        if (length > 0)
            s = s.substr(s.size() - length, length) + s.substr(0, s.size() - length);
        else
            s = s.substr(length, s.size() - length) + s.substr(0, length);
        return s;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> shift;
    shift.push_back({0, 1});
    shift.push_back({1, 2});
    assert("cab" == sol.stringShift("abc", shift));
    shift.clear();
    shift = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
    assert("efgabcd" == sol.stringShift("abcdefg", shift));
    shift = {{0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2}};
    assert("hcjwpdh" == sol.stringShift("wpdhhcj", shift));
    return 0;
}