#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int mx = INT_MIN;
        for (auto c : candies) {
            mx = max(mx, c);
        }
        vector<bool> maxcandies;
        for (auto c : candies) {
            if (c + extraCandies >= mx) {
                maxcandies.push_back(true);
            } else
                maxcandies.push_back(false);
        }
        return maxcandies;
    }
};

int main() {
    Solution sol;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> output = {true, true, true, false, true};
    vector<bool> returned = sol.kidsWithCandies(candies, extraCandies);
    for (auto i = 0; i < output.size(); i++)
        assert(returned[i] == output[i]);

    candies = {4, 2, 1, 1, 2};
    extraCandies = 1;
    output = {true, false, false, false, false};
    returned = sol.kidsWithCandies(candies, extraCandies);
    for (auto i = 0; i < output.size(); i++)
        assert(returned[i] == output[i]);

    candies = {12, 1, 12};
    extraCandies = 10;
    output = {true, false, true};
    returned = sol.kidsWithCandies(candies, extraCandies);
    for (auto i = 0; i < output.size(); i++)
        assert(returned[i] == output[i]);

    return 0;
}
