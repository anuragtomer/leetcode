#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    vector<string> str_nums;
    for (auto num : nums) {
      str_nums.push_back(to_string(num));
    }
    sort(str_nums.begin(), str_nums.end(),
         [](string &a, string &b) { return a + b > b + a; });
    if (str_nums[0] == "0")
      return "0";
    string result;
    for (auto str : str_nums)
      result.append(str);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {10, 2};
  assert(sol.largestNumber(nums) == "210");
  cout << "Pass 1\n";
  nums = {3, 30, 34, 5, 9};
  assert(sol.largestNumber(nums) == "9534330");
  cout << "Pass 2\n";
  return 0;
}

