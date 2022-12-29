#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool confusingNumber(int n) {
    unordered_map<int, pair<bool, int>> confusing = {
      {0, {true, 0}},  {1, {true, 1}},  {2, {false, 2}}, {3, {true, 3}},
      {4, {false, 4}}, {5, {false, 5}}, {6, {true, 9}},  {7, {false, 7}},
      {8, {true, 8}},  {9, {true, 6}}};
    string o_string, n_string;
    while (n) {
      int digit = n % 10;
      n /= 10;
      if (not confusing[digit].first)
        return false;
      n_string.push_back('0' + confusing[digit].second);
      o_string.push_back('0' + digit);
    }
    return n_string != o_string;
  }
};

int main() {
  Solution sol;
  assert(not sol.confusingNumber(25));
  assert(not sol.confusingNumber(11));
  assert(sol.confusingNumber(89));
  assert(sol.confusingNumber(6));
  return 0;
}
