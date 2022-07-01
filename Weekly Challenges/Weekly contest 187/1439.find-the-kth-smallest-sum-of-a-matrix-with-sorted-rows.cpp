#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int kthSmallest(vector<vector<int>> &A, int k) {
        /**
         * Algorithm:
         * ==========
         * Loop over all the vectors and keep saving sum of pairs that will be made by ints in current vector with
         * previous sums. Sort them up. And discard all the values beyond the size k. This way, we keep only top k sums.
         * Return the last element.
         */
        int n = A.size();
        int m = A[0].size();
        vector<int> B;   // keeps summed vectors max capped to size k.
        vector<int> pre; // kind of saves the sum of vectors made by taking 1 from each sorted row vector till 'i'.
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int j = 0; j < m; j++) {
                    // push first sorted row vector. This initialization is done only once.
                    B.push_back(A[i][j]);
                }
            } else {
                swap(B, pre); // Discard the previous. Save current sums formed by adding previous row to existing sums.
                B.clear();
                for (auto p : pre) {
                    for (auto a : A[i]) {
                        B.push_back(p + a); // Make new sums. Take the values in latest i, add them up with the sums
                                            // that we already have.
                    }
                }
            }
            sort(B.begin(), B.end());
            if (B.size() > k)
                // If there are more sums saved in k, remove them. We need to keep track of top k sums.
                B.resize(k);
        }
        return B[k - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    assert(7 == sol.kthSmallest(mat, k));

    mat = {{1, 3, 11}, {2, 4, 6}};
    k = 9;
    assert(17 == sol.kthSmallest(mat, k));

    mat = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    k = 7;
    assert(9 == sol.kthSmallest(mat, k));

    mat = {{1, 1, 10}, {2, 2, 9}};
    k = 7;
    assert(12 == sol.kthSmallest(mat, k));

    return 0;
}
