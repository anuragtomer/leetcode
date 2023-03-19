#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string stringShift(string s, vector<vector<int>> shifts) {
    int final_shift = 0;
    for (auto shift : shifts) {
      if (shift[0] == 0)
        final_shift += shift[1];
      else
        final_shift -= shift[1];
    }
    string result;
    for (int i = (final_shift + s.size()) % s.size(), j = 0; j < s.size();
         ++j, i = (i + 1) % s.size()) {
      result.push_back(s[i]);
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(sol.stringShift("abc", {{0, 1}, {1, 2}}) == "cab");
  cout << "Pass 1" << endl;
  assert(sol.stringShift("abcdefg", {{1, 1}, {1, 1}, {0, 2}, {1, 3}}) ==
         "efgabcd");
  cout << "Pass 2" << endl;
  return 0;
}
