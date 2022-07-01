#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pancakeSort(vector<int> arr) {
    vector<int> result;
    int x, i;
    for (x = arr.size(); x > 0; --x) {
      for (i = 0; arr[i] != x; ++i)
        ;
      reverse(arr.begin(), arr.begin() + i + 1);
      result.push_back(i + 1);
      reverse(arr.begin(), arr.begin() + x);
      if (result.back() == x)
        result.pop_back();
      else
        result.push_back(x);
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, 2, 4, 1};
  vector<int> result = sol.pancakeSort(arr);
  for (auto res : result)
    cout << res << " ";
  return 0;
}

