#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
     * Algo:
     * Get the max water by keeping 2 pointers - 1st at beginning, 2nd at end.
     * Now, increase/decrease the pointers until you find a height that might get you more area (new
     * height is greater than previous heights).
     */
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1; // 2 pointers inited to first and last.
    int maxWater = 0;
    while (i < j) {
      // Calculate the lower of the two height.
      int minH = min(height[i], height[j]);
      // Calculate the max area between i and j.
      maxWater = max(maxWater, minH * (j - i));
      while (height[i] <= minH && i < j)
        i++; // Search for a higher building than current i.
      while (height[j] <= minH && i < j)
        j--; // Search for a higher building than current j.
    }
    return maxWater;
  }
};

int main() {
  Solution sol;
  vector<int> height;
  height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  assert(sol.maxArea(height) == 49);
  height = {1, 1};
  assert(sol.maxArea(height) == 1);
  return 0;
}
