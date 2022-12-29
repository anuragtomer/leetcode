#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestUniqueNumber(vector<int> A) {
    unordered_map<int, int> int_count;
    for (auto num : A) {
      int_count[num]++;
    }
    int max_num = INT_MIN;
    for (auto num : A) {
      if (int_count[num] == 1 && max_num < num) {
        max_num = num;
      }
    }
    return max_num == INT_MIN ? -1 : max_num;
  }
};

int main() {
  Solution sol;
  assert(sol.largestUniqueNumber({5, 7, 3, 9, 4, 9, 8, 3, 1}) == 8);
  assert(sol.largestUniqueNumber({9, 9, 8, 8}) == -1);
  return 0;
}
