#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int sumSubarrayMins(vector<int> &arr) {
        long n = arr.size(), MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            left[i] = count;
        }
        st = stack<pair<int, int>>();
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            right[i] = count;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (static_cast<long>(arr[i]) * left[i] * right[i]) % MOD) % MOD;
        }
        return sum;
    }
};
int main() {
    Solution sol;

    return 0;
}

