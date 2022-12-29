#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;

class Solution {
 public:
  void reverseString(vector<char> &s) { reverse(s.begin(), s.end()); };
};

int main() {
  Solution sol;
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
  sol.reverseString(s);
  assert(vectors::match_unsorted_vecs(s, expected));
  s = {'H', 'a', 'n', 'n', 'a', 'h'};
  expected = {'h', 'a', 'n', 'n', 'a', 'H'};
  sol.reverseString(s);
  assert(vectors::match_unsorted_vecs(s, expected));
  return 0;
}
