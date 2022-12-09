#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOriginalArray(vector<int> &changed) {
    if (changed.size() % 2 != 0)
      return {};
    unordered_map<int, int> orig;
    for (auto num : changed) {
      orig[num]++;
    }
    sort(changed.begin(), changed.end());
    vector<int> result;
    for (auto val : changed) {
      if (val == 0) {
        if (orig[val] > 0 && orig[val] % 2 == 0) {
          result.insert(result.end(), val, orig[val] / 2);
          orig.erase(val);
        }
      } else {
        if (orig.find(val) != orig.end() && orig.find(2 * val) != orig.end()) {
          result.push_back(val);
          orig.erase(orig.find(val));
          orig.erase(orig.find(2 * val));
        }
      }
    }
    if (not orig.empty())
      return {};
    return result;
  }
};

int main() {
  Solution sol;
  auto lmatch = [](vector<int> &out, vector<int> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    sort(out.begin(), out.end());
    sort(exp.begin(), exp.end());
    for (int i = 0; i < out.size(); ++i)
      if (out[i] != exp[i])
        return false;
    return true;
  };
  vector<int> changed = {1, 3, 4, 2, 6, 8};
  vector<int> output = sol.findOriginalArray(changed);
  vector<int> expected = {1, 3, 4};
  assert(lmatch(output, expected));
  changed = {6, 3, 0, 1};
  expected = {};
  output = sol.findOriginalArray(changed);
  assert(lmatch(output, expected));
  changed = {1};
  expected = {};
  output = sol.findOriginalArray(changed);
  assert(lmatch(output, expected));
  changed = {0, 0, 0, 0}, expected = {0, 0},
  output = sol.findOriginalArray(changed);
  assert(lmatch(output, expected));
  changed = {2, 1, 2, 4}, expected = {1, 2},
  output = sol.findOriginalArray(changed);
  assert(lmatch(output, expected));
  changed = {4, 4, 16, 20, 8, 8, 2, 10}, expected = {2, 4, 8, 10},
  output = sol.findOriginalArray(changed);
  assert(lmatch(output, expected));
  return 0;
}
