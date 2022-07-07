#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int countDifference(vector<int> &A, vector<int> &B, int num) {
        int countA = 0, countB = 0;
        for (int i = 0; i < A.size(); ++i) {
            if ((A[i] != num) && (B[i] != num))
                return -1;
            if (A[i] != num)
                countA++;
            if (B[i] != num)
                countB++;
        }
        return min(countA, countB);
    }

   public:
    int minDominoRotations(vector<int> &A, vector<int> &B) {
        int res1 = countDifference(A, B, A[0]);
        int res2 = countDifference(A, B, B[0]);
        return min(res1, res2) > 0 ? min(res1, res2) : max(res1, res2);
    }
};

int main() {
    Solution sol;
    vector<int> A = {2, 1, 2, 4, 2, 2};
    vector<int> B = {5, 2, 6, 2, 3, 2};
    assert(2 == sol.minDominoRotations(A, B));
    return 0;
}

