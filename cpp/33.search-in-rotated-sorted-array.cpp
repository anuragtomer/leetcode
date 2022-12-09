#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  int findPivot(vector<int> &nums) {
    int lb = 0, ub = nums.size() - 1, mid;
    while (lb < ub) {
      mid = lb + (ub - lb) / 2;
      if (nums[mid] > nums[ub])
        lb = mid + 1;
      else
        ub = mid;
    }
    return lb;
  }

 public:
  int search(vector<int> &nums, int target) {
    int pivot = findPivot(nums);
    int N = nums.size();
    int lb = 0, ub = N - 1, mid, realmid;
    while (lb <= ub) {
      mid = lb + (ub - lb) / 2;
      realmid = (mid + pivot) % N;
      if (nums[realmid] == target)
        return realmid;
      else if (nums[realmid] < target) {
        lb = mid + 1;
      } else
        ub = mid - 1;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  vector<int> nums2 = {0, 1, 2, 3, 4, 5, 6, 7};
  assert(0 == sol.search(nums2, 0));
  assert(3 == sol.search(nums2, 3));
  return 0;
}
