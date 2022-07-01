#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        vector<vector<int>> output;
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            if (A[i][0] >= B[j][0] && A[i][0] <= B[j][1]) { // If A starts in this current B interval.
                int start = A[i][0];
                int end = min(A[i][1], B[j][1]);
                output.push_back({start, end});
            } else if (B[j][0] >= A[i][0] && B[j][0] <= A[i][1]) { // If B starts in this current A interval.
                int start = B[j][0];
                int end = min(B[j][1], A[i][1]);
                output.push_back({start, end});
            }
            // If both conditions were not met, then we don't have an intersection between these two current intervals of A and B and hence don't put anything in output.

            if (A[i][1] < B[j][1]) // If A ends before, go to next interval in A.
                i++;
            else // Else go to next interval in B.
                j++;
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> A, B;
    A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}}, B = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    vector<vector<int>> output = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};
    vector<vector<int>> result = sol.intervalIntersection(A, B);
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i) {
        assert(output[i][0] == result[i][0] && output[i][1] == result[i][1]);
    }
    return 0;
}
