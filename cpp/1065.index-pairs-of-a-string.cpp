#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;
using namespace Vectors;
class Solution {
 public:
  vector<vector<int>> indexPairs(string text, vector<string> words) {
    vector<vector<int>> result;
    for (int i = 0; i < text.size(); ++i) {
      for (auto word : words) {
        if (word.compare(
              string(text.begin() + i, text.begin() + i + word.size())) == 0)
          result.push_back({i, i - 1 + (int)word.size()});
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(Vectors::match_sorted_vecs(
    sol.indexPairs("thestoryofleetcodeandme", {"story", "fleet", "leetcode"}),
    {{3, 7}, {9, 13}, {10, 17}}));
  cout << "Pass 1\n";
  assert(Vectors::match_sorted_vecs(sol.indexPairs("ababa", {"aba", "ab"}),
                                    {{0, 1}, {0, 2}, {2, 3}, {2, 4}}));
  cout << "Pass 2";
  return 0;
}
