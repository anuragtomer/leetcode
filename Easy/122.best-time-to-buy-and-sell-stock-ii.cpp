/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and
 * sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy
 * again).
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        auto curr = prices[0];
        auto prev = prices[0];
        auto profit = 0;
        for (auto day = 1; day < prices.size(); ++day) {
            if (curr > prices[day]) {
                profit += (prev - curr);
                prev = prices[day];
                curr = prices[day];
            } else {
                curr = prices[day];
            }
        }
        if (prev < curr)
            profit += (prev - curr);
        return profit * (-1);
    }
};

int main() {
    Solution sol;
    vector<int> nums{7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(nums);
    return 0;
}