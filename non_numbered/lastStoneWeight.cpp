#include "lib.h"

bool maxfirst (int i, int j) {
    return (i > j);
}
class Solution {
public:
    int lastStoneWeight(vector <int>& stones) {
        while(stones.size() > 1) {
            sort(stones.begin(), stones.end(), maxfirst);
            stones.push_back(stones[0] - stones[1]);
            stones.erase(stones.begin(), stones.begin() + 2);
        }
        return stones[0];
    }
};
int main(){
    Solution sol;
    vector <int> stones = createVector();
    cout << sol.lastStoneWeight(stones);
    return 0;
}
/*
 *  Input: [2,7,4,1,8,1]
 *  Output: 1
 *  Explanation:
 *  We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 *  we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 *  we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 *  we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 */
