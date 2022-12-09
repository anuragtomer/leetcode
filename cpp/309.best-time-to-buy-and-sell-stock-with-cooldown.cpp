#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), i = 1;
        vector<int> buy(n + 1, 0), sell(n + 1, 0);
        buy[0] = INT_MIN;
        for (auto price : prices) {
            buy[i] = max(i == 1 ? -price : sell[i - 2] - price, buy[i - 1]);
            sell[i] = max(buy[i - 1] + price, sell[i - 1]);
            ++i;
        }
        return sell.back();
        /* No vectors needed. Saving on memory:
         int i = 1, n = prices.size();
    int last_buy = INT_MIN, last_last_sell = 0, last_sell = 0, sell = 0, buy = 0;
    for (auto price: prices) {
      buy = max(last_buy, last_last_sell - price);
      sell = max(last_sell, last_buy + price);
      last_buy = buy;
      last_last_sell = last_sell;
      last_sell = sell;
    }
    return sell;
        */
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << sol.maxProfit(prices);
    return 0;
}
