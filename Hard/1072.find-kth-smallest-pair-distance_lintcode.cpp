#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int count = 0;
            int mid = (high - low) / 2 + low;
            for (int right = 0, left = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid)
                    left++;
                count += (right - left);
            }
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1};
    cout << "First" << endl;
    if (0 != sol.smallestDistancePair(nums, 1))
        cout << sol.smallestDistancePair(nums, 1) << endl;
    cout << "Second" << endl;
    if (2 != sol.smallestDistancePair(nums, 3))
        cout << sol.smallestDistancePair(nums, 3) << endl;
    cout << "Third" << endl;
    if (2 != sol.smallestDistancePair(nums, 2))
        cout << sol.smallestDistancePair(nums, 2) << endl;
    return 0;
}

