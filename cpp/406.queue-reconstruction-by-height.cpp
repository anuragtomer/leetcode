#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(),
         [](vector<int> &existing, vector<int> &incoming) {
           if (existing[0] == incoming[0])
             return (existing[1] < incoming[1]); // Smaller position first.
           return existing[0] > incoming[0];     // Higher person first.
         });
    vector<vector<int>> res;
    for (auto p : people) {
      res.insert(res.begin() + p[1], p);
    }
    return res;
  }
};

int main() {
  auto lMatch = [](vector<vector<int>> out, vector<vector<int>> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size())
        return false;
      for (int j = 0; j < out[i].size(); ++j)
        if (out[i][j] != exp[i][j])
          return false;
    }
    return true;
  };
  Solution sol;
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> expected = {{5, 0}, {7, 0}, {5, 2},
                                  {6, 1}, {4, 4}, {7, 1}};
  assert(lMatch(sol.reconstructQueue(people), expected));
  people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
  expected = {{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}};
  assert(lMatch(sol.reconstructQueue(people), expected));
  cout << "All test cases passed.";
  return 0;
}
