#include <cassert>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int lb = 0, ub = nums.size();
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        lb = mid + 1;
      else
        ub = mid;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  assert(true);
  return 0;
}
