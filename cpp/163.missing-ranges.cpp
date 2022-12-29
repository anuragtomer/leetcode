#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"
using namespace std;

class Solution {
 public:
  vector<string> findMissingRanges(vector<int> nums, int lower, int upper) {
    vector<string> result;
    int last_seen = lower - 1;
    for (auto num : nums) {
      if (num > last_seen + 1) {
        if (num - last_seen == 2)
          result.push_back(to_string(last_seen + 1));
        else
          result.push_back(to_string(last_seen + 1) + "->" +
                           to_string(num - 1));
        last_seen = num;
      } else {
        ++last_seen;
      }
    }
    if (last_seen != upper) {
      if (upper - last_seen == 1) {
        result.push_back(to_string(last_seen + 1));
      } else {
        result.push_back(to_string(last_seen + 1) + "->" + to_string(upper));
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> expected = {"2", "4->49", "51->74", "76->99"};
  assert(vectors::match_unsorted_vecs(
    sol.findMissingRanges({0, 1, 3, 50, 75}, 0, 99), expected));
  expected = {"0", "2", "4->49", "51->74", "76->96", "99"};
  assert(vectors::match_unsorted_vecs(
    sol.findMissingRanges({1, 3, 50, 75, 97, 98}, 0, 99), expected));
  expected = {"4->6"};
  assert(vectors::match_unsorted_vecs(
    sol.findMissingRanges({0, 1, 2, 3, 7}, 0, 7), expected));
  expected = {"0->10"};
  assert(
    vectors::match_unsorted_vecs(sol.findMissingRanges({}, 0, 10), expected));
  expected = {"0"};
  assert(
    vectors::match_unsorted_vecs(sol.findMissingRanges({}, 0, 0), expected));
}
