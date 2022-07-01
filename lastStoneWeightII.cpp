
#include <climits>
#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector <int> stones){
        bitset <1501> dp = {1};
        int sumStones = 0;
        for (int stone: stones) {
            sumStones += stone;
            for (int i = 1500; i >= stone; i--) {
                dp[i] = dp[i] + dp[i - stone];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 1500; i++) {
            res = min(res, abs(sumStones - dp[i] * i * 2));
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector <int> stones = {7, 1, 6, 8, 2, 1};
    cout << sol.lastStoneWeightII(stones);
    return 0;
}
