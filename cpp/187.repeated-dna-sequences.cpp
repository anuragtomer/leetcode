#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    unordered_map<string, int> hash;

    for (int i = 0, n = s.size(); i <= n - 10; ++i) {
      string ten_letter_long = s.substr(i, 10);
      hash[ten_letter_long]++;
      if (hash[ten_letter_long] == 2) {
        result.push_back(ten_letter_long);
      }
    }
    return result;
  }
};

int main() {
  auto lMatch = [](vector<string> out, vector<string> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    for (int i = 0; i < out.size(); ++i) {
      if (out[i] != exp[i])
        return false;
    }
    return true;
  };

  Solution sol;
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> expected = {"AAAAACCCCC", "CCCCCAAAAA"};
  assert(lMatch(sol.findRepeatedDnaSequences(s), expected));
  s = "AAAAAAAAAAAAA";
  expected = {"AAAAAAAAAA"};
  assert(lMatch(sol.findRepeatedDnaSequences(s), expected));
  return 0;
}
