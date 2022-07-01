#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestOnes(vector<int> &A, int K) {
        int res = INT_MIN;
        int n = A.size();
        int count = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0)
                count++;
            while (count > K && j < n) {
                if (A[j] == 0)
                    count--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    assert(6 == sol.longestOnes(A, K));
    A = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    K = 3;
    assert(10 == sol.longestOnes(A, K));
    return 0;
}
