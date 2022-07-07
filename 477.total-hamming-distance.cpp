#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
     * @param nums: the gievn integers
     * @return: the total Hamming distance between all pairs of the given numbers
     */
  int totalHammingDistance(vector<int> &nums) {
    int result = 0, n = nums.size(), count = 0;
    for (int i = 0; i < 32; ++i) {
      count = 0;
      for (int j = 0; j < n; ++j)
        count += ((nums[j] >> i) & 1);
      result += (count * (n - count));
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

