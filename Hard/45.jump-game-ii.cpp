#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int> &nums) {
        int can_reach = -1, n = nums.size(), jump = 0;
        if (n <= 1)
            return 0;
        pair<int, int> interval = {0, 0};
        while (true) {
            jump++;
            for (int i = interval.first; i <= interval.second; ++i) {
                can_reach = max(can_reach, i + nums[i]);
            }
            if (can_reach >= n - 1) {
                return jump;
            }
            interval = {interval.second + 1, can_reach};
            cout << interval.first << " " << interval.second << endl;
            if (interval.second < interval.first)
                return -1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.jump(nums) << endl;
    return 0;
}
