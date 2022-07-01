#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        unordered_map<int, int> count;
        for (auto domino : dominoes) {
            sort(domino.begin(), domino.end());
            count[domino[0] * 10 + domino[1]]++;
        }
        int result = 0;
        for (auto pairs : count)
            if (pairs.second >= 2)
                result += (pairs.second * (pairs.second - 1)) / 2;
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

