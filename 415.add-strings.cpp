/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include<iostream>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size() - 1;
        int sz2 = num2.size() - 1;
        int carry = 0;
        stack<char> st;
        string sum;
        int i, j;
        for(i = sz1, j = sz2; i >= 0 && j >= 0;--i, --j) {
            int k = (num1[i] - 48) + (num2[j] - 48) + carry;
            carry = k/10;
            k = k%10;
            st.push(k+48);
        }
        for(;i >= 0;--i) {
            int k = (num1[i] - 48) + carry;
            carry = k/10;
            k = k%10;
            st.push(k+48);
        }
        for(; j>= 0;--j) {
            int k = (num2[j] - 48) + carry;
            carry = k/10;
            k = k%10;
            st.push(k+48);
        }
        if (carry != 0)
            st.push(carry+48);
        while(st.empty() == false) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string num1, num2;
    cin >> num1;
    cin >> num2;
    cout << sol.addStrings(num1, num2);
    return 0;
}