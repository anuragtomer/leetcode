#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        if (nums.empty())
            return {};
        pair<int, int> range = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1)
                range.second++;
            else {
                if (range.first == range.second)
                    result.push_back(to_string(range.first));
                else
                    result.push_back(to_string(range.first) + "->" + to_string(range.second));
                range = {nums[i], nums[i]};
            }
        }
        if (range.first == range.second)
            result.push_back(to_string(range.first));
        else
            result.push_back(to_string(range.first) + "->" + to_string(range.second));
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

