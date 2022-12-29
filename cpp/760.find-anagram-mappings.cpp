#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "lib.h"
using namespace std;

class Solution {
 public:
  vector<int> anagramMappings(vector<int> A, vector<int> B) {
    unordered_map<int, vector<int>> hash;
    int i = 0;
    for (auto num : B) {
      hash[num].push_back(i++);
    }
    vector<int> result;
    for (auto num : A) {
      if (not hash[num].empty()) {
        result.push_back(hash[num].back());
        hash[num].pop_back();
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  assert(Vectors::match_unsorted_vecs(
    sol.anagramMappings({12, 28, 46, 32, 50}, {50, 12, 32, 46, 28}),
    {1, 4, 3, 2, 0}));
  return 0;
}
