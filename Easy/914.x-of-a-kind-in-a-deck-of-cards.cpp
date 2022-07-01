#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool hasGroupsSizeX(vector<int> &deck) {
        if (deck.size() <= 1)
            return false;
        unordered_map<int, int> hash;
        for (auto d : deck) {
            hash[d]++;
        }
        int mn = INT_MAX;
        for (auto it : hash) {
            if (mn == INT_MAX)
                mn = it.second;
            else {
                mn = gcd(mn, it.second);
                if (mn == 1)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    assert(sol.hasGroupsSizeX(deck));
    return 0;
}

