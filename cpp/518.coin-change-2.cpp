#include <chrono>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    /*
     * Algorithm:
     * We will start with the smallest coin.
     * With the smallest coin, we update what all possible combinations we can have for each of the amount.
     * Update is done as follows:
     * no_of_ways[amount_i] = no_of_ways[amount_i] + no_of_ways[amount_i - current_coin_value];
     * Update for each amount is done at max of no of coin denominations.
     */
   public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        if (n == 0) {
            if (amount == 0)
                return 1;
            else
                return 0;
        }
        sort(begin(coins), end(coins));
        vector<int> no_of_ways(amount + 1, 0);
        no_of_ways[0] = 1;
        for (auto coin : coins) {                // For each of the coin denomination.
            for (int j = coin; j <= amount; j++) // Do for all possible 'amounts'.
                no_of_ways[j] += no_of_ways[j - coin];
        }
        // By now, we have all the ways for each of the amount <= amount. The question asked for 'amount', we return that.
        return no_of_ways[amount];
    }
};

int main() {
    Solution sol;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    assert(4 == sol.change(amount, coins));
    amount = 3, coins = {2};
    assert(0 == sol.change(amount, coins));
    amount = 10, coins = {10};
    assert(1 == sol.change(amount, coins));
    amount = 10, coins = {1, 2, 5};
    assert(10 == sol.change(amount, coins));
    amount = 500, coins = {1, 2, 5};
    assert(12701 == sol.change(amount, coins));
    return 0;
}
