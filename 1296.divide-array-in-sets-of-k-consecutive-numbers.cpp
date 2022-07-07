#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        multiset<int> set(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for (auto num : nums) {
            if (set.find(num) != set.end()) {
                int count = 0;
                while (count < k) {
                    if (set.find(num + count) == set.end())
                        return false;
                    else
                        set.erase(set.find(num + count));
                    ++count;
                }
            }
        }
        return set.empty();
    }
};

int main() {
    Solution sol;

    return 0;
}

