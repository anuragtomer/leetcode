/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void reverse(vector<int> &output) {
        int end = output.size() - 1;
        for (int i=0; i < end; i++, end--)
            swap(output[i], output[end]);
    }

    vector<int> plusOne(vector<int>& digits) {
        vector<int> output;
        int last = digits[digits.size() - 1] + 1;
        output.push_back(last%10);
        last = last/10;
        for (int i = digits.size() - 2; i >= 0; --i) {
            last = last + digits[i];
            output.push_back(last%10);
            last = last / 10;
        }
        if (last != 0)
            output.push_back(last);
        reverse(output);
        return output;
    }
};
// @lc code=end

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
        cin >> digits[i];
    digits = sol.plusOne(digits);
    for (auto i: digits)
        cout << i << " ";
    return 0;
}