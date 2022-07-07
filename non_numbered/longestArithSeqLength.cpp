#include "lib.h"
#include <unordered_map>

class Solution {
public:
    int longestArithSeqLength(vector <int>& A) {
        if (A.size() == 1) {
            return 1;
        }
        int res = 2;
        unordered_map <int, unordered_map <int, int> > dp;
        for (unsigned i = 0; i < A.size(); i++) {
            for (unsigned j = i + 1; j < A.size(); j++) {
                int d = A[j] - A[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(dp[d][j], res);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector <int> input;
    input = createVector();
    cout << sol.longestArithSeqLength(input);
    return 0;
}
/*
 *  Input: [3,6,9,12]
 *  Output: 4
 *
 *  Input: [9,4,7,2,10]
 *  Output: 3
 *
 *  Input: [20,1,15,3,10,5,8]
 *  Output: 4
 */
