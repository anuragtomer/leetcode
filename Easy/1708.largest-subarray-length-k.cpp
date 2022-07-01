#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param A: the array
     * @param K: the length
     * @return: the largest subarray
     */
    vector<int> largestSubarray(vector<int> &A, int K) {
        int start = 0;
        for (int i = 0; i < A.size() - K + 1; ++i) {
            for (int j = 0; j < K && start + j < A.size() && i + j < A.size(); ++j) {
                if (A[start + j] < A[i + j]) {
                    start = i;
                    break;
                } else if (A[start + j] > A[i + j]) {
                    break;
                }
            }
        }
        return vector<int>(A.begin() + start, A.begin() + start + K);
    }
};

int main() {
    Solution sol;

    return 0;
}

