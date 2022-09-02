#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> greaterNum;
    stack<int> greater;
    for (int i = 0; i < nums2.size(); ++i) {
      while (!greater.empty() && nums2[greater.top()] < nums2[i]) {
        greaterNum[nums2[greater.top()]] = nums2[i];
        greater.pop();
      }
      greater.push(i);
    }
    vector<int> result;
    for (auto num : nums1) {
      if (greaterNum.find(num) != greaterNum.end()) {
        result.push_back(greaterNum[num]);
      } else {
        result.push_back(-1);
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  auto lmatch = [](vector<int> &exp, vector<int> &out) {
    if (exp.size() != out.size())
      return false;
    for (int i = 0; i < exp.size(); ++i)
      if (exp[i] != out[i])
        return false;
    return true;
  };
  vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
  vector<int> expected = {-1, 3, -1};
  vector<int> output = sol.nextGreaterElement(nums1, nums2);
  assert(lmatch(expected, output));
  nums1 = {2, 4}, nums2 = {1, 2, 3, 4}, expected = {3, -1};
  output = sol.nextGreaterElement(nums1, nums2);
  assert(lmatch(expected, output));
  return 0;
}
