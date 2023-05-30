#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
       int findKthLargest(vector<int>& nums, int k) {
       multiset<int> st;
       for (auto num: nums) {
       st.insert(num);
       if (st.size() > k)
       st.erase(st.begin());
       }
       return *st.begin();
       }
  */
  /*
   int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
      pq.push(num);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
  */
  int findKthLargest(vector<int> &nums, int k) {
    int right_place = -1;
    int n = nums.size();
    int target_position = n - k;
    int range_left = 0, range_right = n - 1;
    while (right_place != target_position) {
      int element = nums[range_left];
      int i = range_left + 1, j = range_right;
      while (i <= j) {
        if (nums[i] >= element) {
          swap(nums[i], nums[j]);
          --j;
        } else {
          ++i;
        }
      }
      swap(nums[range_left], nums[j]);
      if (j == target_position)
        return nums[j];
      if (j < target_position)
        range_left = j + 1;
      else
        range_right = j - 1;
    }
    return -1;
  }
  /*
   * - Pick first element and partition elements around it.
   * - Place this element at its right place.
   * - If its right place is == k, return it.
   * - If right place is > k, the pick first element and place elements around it in first partition.
   * - If right place is < k, then pick right place + 1th element and place elements around it in second partition.
   **/
};

int main() {
  Solution sol;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  assert(sol.findKthLargest(nums, k) == 5);
  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  k = 4;
  assert(sol.findKthLargest(nums, k) == 4);
  nums = {99, 99};
  k = 1;
  assert(sol.findKthLargest(nums, k) == 99);
  return 0;
}
