#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class SolutionA {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // Idea is, front should have the highest element of the window, and we only keep potential max numbers.
        // Any new element, we push it at the back(smaller side).
        // If there front most element is out of k sized window, pop it off.
        // If the element at the back is smaller that incoming number, pop it off.
        vector<int> result = vector<int>();
        if (k == 0)
            return result;
        deque<int> w;
        for (int i = 0, n = static_cast<int>(nums.size()); i < n; ++i) {
            while (!w.empty() && w.front() <= i - k) { // If front is now gone out of window, pop it off.
                w.pop_front();
            }
            while (!w.empty() && nums[w.back()] <= nums[i]) { // If there are smaller elements at the back, pop them.
                                                              // They are not candidates for max element.
                w.pop_back();
            }
            w.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[w.front()]);
        }
        return result;
    }
};
/* Another solution along the same lines */
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        int left = 0, right = 0, n = nums.size();
        deque<int> dq;
        while (right < n) {
            while (!dq.empty() && dq.back() < nums[right])
                dq.pop_back();
            dq.push_back(nums[right]);
            if (right - left + 1 >= k) {
                result.push_back(dq.front());
                if (nums[left] == dq.front())
                    dq.pop_front();
                ++left;
            }
            ++right;
        }
        return result;
    }
};
int main() {
    Solution sol;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = {3, 3, 5, 5, 6, 7};
    vector<int> output = sol.maxSlidingWindow(nums, 3);
    assert(output.size() == result.size());
    for (int i = 0; i < output.size(); ++i)
        assert(output[i] == result[i]);
    return 0;
}

/*
IDX:0 1  2  3 4 5 6 7
VAL:1 3 -1 -3 5 3 6 7      Deque (contains indices)    Result
    |----|                 1 2                         3 (nums[1])
      |-----|              1 2 3                       3
         |----|            4                           5
            |---|          4 5                         5
              |---|        6                           6
                |---|      7                           7
*/
