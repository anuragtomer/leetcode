#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int friendRequest(vector<int> &age) {
    int requests = 0;
    for (int i = 0, n = age.size(); i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        if (age[j] <= (age[i] * 0.5 + 7))
          continue;
        if (age[j] > age[i])
          continue;
        if (age[j] < 100 && age[i] > 100)
          continue;
        ++requests;
      }
    }
    return requests;
  }
};
int main() {
  Solution sol;

  return 0;
}

