#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int> &nums) {
        map<int, int> hash;
        int count = 0, maxLength = 0, i = 0;
        hash[count] = -1;
        for (auto num : nums) {
            count += (num == 0) ? -1 : 1;
            if (hash.find(count) == hash.end()) {
                hash[count] = i;
            } else {
                maxLength = max(maxLength, i - hash[count]);
            }
            i++;
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1};
    assert(2 == sol.findMaxLength(nums));
    nums = {0, 1, 0};
    assert(2 == sol.findMaxLength(nums));
    return 0;
}
