#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int noRobbery = 0, robbery = nums[0], currentHouse;
        for (int i = 1, n = nums.size(); i < n; ++i) {
            currentHouse = max(noRobbery + nums[i], robbery);
            noRobbery = robbery;
            robbery = currentHouse;
        }
        return robbery;
    }
};

int main() {
    Solution sol;

    return 0;
}

