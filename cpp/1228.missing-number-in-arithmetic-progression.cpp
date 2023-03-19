#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> arr) {
    if (arr.size() < 2) {
      return -1;
    }
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); ++i) {
      if (diff != arr[i] - arr[i - 1]) {
        if (diff < 0)
          return arr[i - 1] - (max(diff, (arr[i] - arr[i - 1])));
        else
          return arr[i - 1] + (min(diff, (arr[i] - arr[i - 1])));
      }
    }
    return arr.back() + diff;
  }
};

int main() {
  Solution sol;
  assert(sol.missingNumber({5, 7, 11, 13}) == 9);
  cout << "Pass 1" << endl;
  assert(sol.missingNumber({15, 13, 12}) == 14);
  cout << "Pass 2" << endl;
  return 0;
}
