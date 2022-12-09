#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int n = garbage.size(), g = 0, m = 0, p = 0;
    vector<int> gtime(n, 0), mtime(n, 0), ptime(n, 0);
    for (int i = 0; i < n; ++i) {
      if (i) {
        gtime[i] = gtime[i - 1] + travel[i - 1];
        mtime[i] = mtime[i - 1] + travel[i - 1];
        ptime[i] = ptime[i - 1] + travel[i - 1];
      }
      for (char j : garbage[i]) {
        if (j == 'G')
          g = ++gtime[i];
        if (j == 'M')
          m = ++mtime[i];
        if (j == 'P')
          p = ++ptime[i];
      }
    }
    return g + m + p;
  }
};
int main() {
  Solution sol;
  vector<string> garbage = {"G", "P", "GP", "GG"};
  vector<int> travel = {2, 4, 3};
  assert(21 == sol.garbageCollection(garbage, travel));
  garbage = {"MMM", "PGM", "GP"};
  travel = {3, 10};
  assert(37 == sol.garbageCollection(garbage, travel));
  return 0;
}
