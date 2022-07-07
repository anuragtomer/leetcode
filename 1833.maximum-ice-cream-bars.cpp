#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (auto cost : costs) {
            coins -= cost;
            if (coins >= 0)
                ++count;
            else
                break;
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> costs = {1, 3, 2, 4, 1};
    assert(4 == sol.maxIceCream(costs, 7));
    return 0;
}

