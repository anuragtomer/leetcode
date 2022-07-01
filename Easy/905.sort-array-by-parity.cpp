/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */
/* #include<iostream>
#include<vector>
using namespace std;
 */
// @lc code=start
class Solution {
public:
    void swapelems(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    vector<int> sortArrayByParity(vector<int>& A) {
        int evenIndex = -1;
        int oddIndex = A.size();
        for (int i = 0; i < oddIndex; ++i) {
            if (A[i] % 2 == 0) { // Current element is even, move it to left side.
                evenIndex++;
                swapelems(A[evenIndex], A[i]);
            } else {
                oddIndex--;
                swapelems(A[oddIndex], A[i]);
                i--;
            }
        }
        return A;
    }
};
// @lc code=end
/* int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> output = sol.sortArrayByParity(A);
    for (int i: output)
        cout << i << " ";
    return 0;
}
 */