#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    void print(vector<vector<int>> dp) {
        for (vector<int> a: dp) {
            for (int i : a) {
                cout << " " <<i;
            }
            cout << "\n";
        }
    }
    int maxCoinsDP(vector<int> &iNums) {
        vector<int> nums(iNums.size() + 2, 1);
        int n = 1;
        for (int x : iNums) if (x > 0) nums[n++] = x;
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j] means what is the best way to burst coins in range (i, j) excluding i'th and j'th ballons.
        print(dp);
        for (int k = 2; k < n; ++k) {
            cout<< "For k: "<<k<<"\n";
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i){
                    dp[left][right] = max(dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                    print(dp);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {3,1,5,8};
    cout << sol.maxCoinsDP(nums);
    return 0;
}