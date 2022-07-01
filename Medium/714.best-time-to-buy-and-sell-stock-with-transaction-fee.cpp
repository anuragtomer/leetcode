#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size(), i = 1;
        vector<int> buy(n + 1, 0), sell(n + 1, 0);
        buy[0] = INT_MIN;
        for (auto price : prices) {
            buy[i] = max(buy[i - 1], sell[i - 1] - price);
            sell[i] = max(sell[i - 1], buy[i - 1] == INT_MIN ? INT_MIN : buy[i - 1] + price - fee);
            ++i;
        }
        return sell.back();
    }
};

int main() {
    Solution sol;

    return 0;
}

