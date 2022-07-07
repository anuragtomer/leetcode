#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeightII(vector<int> &stones) {
        bitset<1501> possible_sums = {1};
        int totalSum = 0;
        for (auto stone : stones) {
            totalSum += stone;
            for (int i = 1500; i >= stone; --i) {
                possible_sums[i] = possible_sums[i] + possible_sums[i - stone];
            }
        }
        // By now, I've marked all the possible sums using the input stones vector.
        /*
            (1) S1 + S2  = S
            (2) S1 - S2 = diff
            => 2 * S2 = S - diff
            => diff = s - 2 * s2
            Find min(diff)
        // One way to minimize result.
        int result = INT_MAX;
        for (int i = 0; i < 1500; ++i)
            result = min(result, abs(totalSum - 2 * possible_sums[i] * i));
        return result;
        */
        /*
            Another way:
                To find min(diff), we should do max(S2);
                So check which highest possible_sum is set.
        */
        for (int i = totalSum / 2; i >= 0; --i) {
            if (possible_sums[i])
                return totalSum - 2 * i;
        }
        return 0;
    }
};

/*
 * Progression through one of the examples.
2 7 4 1 8 1
dp[0] = 1
==> 2
Sum: 2
dp[2] = 1
==> 7
Sum: 9
dp[9] = 1
dp[7] = 1
==> 4
Sum: 13
dp[13] = 1
dp[11] = 1
dp[6] = 1
dp[4] = 1
==> 1
Sum: 14
dp[14] = 1
dp[12] = 1
dp[10] = 1
dp[8] = 1
dp[5] = 1
dp[3] = 1
dp[1] = 1
==> 8
Sum: 22
dp[22] = 1
dp[21] = 1
dp[20] = 1
dp[19] = 1
dp[18] = 1
dp[17] = 1
dp[16] = 1
dp[15] = 1
==> 1
Sum: 23
dp[23] = 1
*/

int main() {
    Solution sol;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    assert(1 == sol.lastStoneWeightII(stones));
    return 0;
}

