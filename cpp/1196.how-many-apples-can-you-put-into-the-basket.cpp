#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxNumberOfApples(vector<int> apples) {
    sort(apples.begin(), apples.end());
    int count = 0, current_sum = 0;
    for (auto apple : apples) {
      if (current_sum + apple <= 5000) {
        ++count;
        current_sum += apple;
      } else {
        return count;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  assert(sol.maxNumberOfApples({100, 200, 150, 1000}) == 4);
  assert(sol.maxNumberOfApples({900, 950, 800, 1000, 700, 800}) == 5);

  return 0;
}
