#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> count(nums.size() + 1, 0);
        for (auto num : nums)
            count[num]++;
        int n = nums.size();
        vector<int> result;
        for (int i = 1; i <= n; ++i)
            if (count[i] == 0)
                result.push_back(i);
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

