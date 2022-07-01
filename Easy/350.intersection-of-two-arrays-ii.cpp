#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> hash;
    for (auto num : nums1)
      hash[num]++;
    vector<int> result;
    for (auto num : nums2)
      if (hash.count(num)) {
        hash[num]--;
        if (hash[num] == 0)
          hash.erase(num);
        result.push_back(num);
      }
    return result;
  }
};

int main() {
  Solution sol;

  return 0;
}

