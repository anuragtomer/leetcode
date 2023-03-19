#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    sort(properties.begin(), properties.end(),
         [](vector<int> &a, vector<int> &b) {
           return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
         });
    int n = properties.size(), count = 0, weakest = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
      if (properties[i][1] < weakest)
        ++count;
      weakest = max(properties[i][1], weakest);
    }
    return count;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> properties = {{5, 5}, {6, 3}, {3, 6}};
  assert(0 == sol.numberOfWeakCharacters(properties));
  properties = {{2, 2}, {3, 3}};
  assert(1 == sol.numberOfWeakCharacters(properties));
  properties = {{1, 5}, {10, 4}, {4, 3}};
  assert(1 == sol.numberOfWeakCharacters(properties));
  properties = {{7, 7}, {1, 2},  {9, 7}, {7, 3}, {3, 10},
                {9, 8}, {8, 10}, {4, 3}, {1, 5}, {1, 5}};
  assert(6 == sol.numberOfWeakCharacters(properties));
  return 0;
}
