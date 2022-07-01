#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        int minPriceIndex = 0, maxPriceIndex = 0, profit = 0;
        for (int i = 0, n = prices.size(); i < n; ++i) {
            if (prices[i] < prices[minPriceIndex]) {
                profit = max(profit, prices[maxPriceIndex] - prices[minPriceIndex]);
                minPriceIndex = i;
                maxPriceIndex = i;
            }
            if (prices[i] > prices[maxPriceIndex]) {
                maxPriceIndex = i;
            }
        }
        return max(profit, prices[maxPriceIndex] - prices[minPriceIndex]);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    assert(5 == sol.maxProfit(prices));

    return 0;
}

