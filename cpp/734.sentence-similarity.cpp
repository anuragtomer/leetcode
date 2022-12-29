#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool areSentencesSimilar(vector<string> A, vector<string> B,
                           vector<vector<string>> similarPairs) {
    if (A.size() != B.size())
      return false;
    unordered_map<string, string> hash;
    for (auto pairs : similarPairs) {
      hash[pairs[0]] = pairs[1];
      hash[pairs[1]] = pairs[0];
    }
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != B[i] && A[i] != hash[B[i]] && hash[A[i]] != B[i])
        return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(sol.areSentencesSimilar(
    {"great", "acting", "skills"}, {"fine", "drama", "talent"},
    {{"great", "fine"}, {"acting", "drama"}, {"skills", "talent"}}));

  assert(sol.areSentencesSimilar({"great"}, {"great"}, {}));

  assert(not sol.areSentencesSimilar({"great"}, {"doubleplus", "good"}, {}));
  return 0;
}
