#include <algorithm>
#include <cassert>
#include <vector>

#include "lib.hpp"
using namespace std;

class Solution {
 public:
  vector<vector<int>> highFive(vector<vector<int>> student_scores) {
    sort(student_scores.begin(), student_scores.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
         });
    vector<vector<int>> result;
    for (int i = 0; i < student_scores.size();) {
      int k = 0;
      int sum = 0;
      while (i + k < student_scores.size() &&
             student_scores[i + k][0] == student_scores[i][0]) {
        if (k < 5)
          sum += student_scores[i + k][1];
        ++k;
      }
      result.push_back({student_scores[i][0], sum / 5});
      i += k;
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(Vectors::match_sorted_vecs(sol.highFive({{1, 91},
                                                  {1, 92},
                                                  {2, 93},
                                                  {2, 97},
                                                  {1, 60},
                                                  {2, 77},
                                                  {1, 65},
                                                  {1, 87},
                                                  {1, 100},
                                                  {2, 100},
                                                  {2, 76}}),
                                    {{1, 87}, {2, 88}}));
  cout << "Pass";
  return 0;
}
