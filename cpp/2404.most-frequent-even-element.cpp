#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int mostFrequentEven(vector<int> &nums) {
    int result = INT_MAX, count = 0;
    unordered_map<int, int> evenCount;
    for (auto num : nums)
      if (num % 2 == 0) {
        evenCount[num]++;
        if (evenCount[num] > count) {
          count = evenCount[num];
          result = num;
        } else if (evenCount[num] == count)
          result = min(result, num);
      }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {0, 1, 2, 2, 4, 4, 1};
  assert(2 == sol.mostFrequentEven(nums));
  nums = {4, 4, 4, 9, 2, 4};
  assert(4 == sol.mostFrequentEven(nums));
  nums = {29, 47, 21, 41, 13, 37, 25, 7};
  assert(-1 == sol.mostFrequentEven(nums));
  return 0;
}
