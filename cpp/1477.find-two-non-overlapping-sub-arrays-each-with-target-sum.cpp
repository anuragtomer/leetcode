#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  vector<int> minLenWithTarget(vector<int> &arr, int target) {
    unordered_map<int, int> hash;
    hash[0] = -1;
    int n = arr.size();
    vector<int> result(n, n + 1);
    int runningSum = 0;
    for (int i = 0; i < n; ++i) {
      runningSum += arr[i];
      int len = INT_MAX;
      if (hash.find(runningSum - target) != hash.end())
        len = i - hash[runningSum - target];
      hash[runningSum] = i;
      result[i] = i == 0 ? len : min(len, result[i - 1]);
    }
    return result;
  }

 public:
  int minSumOfLengths(vector<int> &arr, int target) {
    vector<int> left = minLenWithTarget(arr, target);
    vector<int> revArray(arr.rbegin(), arr.rend());
    vector<int> right = minLenWithTarget(revArray, target);
    int minLen = INT_MAX;
    for (int i = 0, n = arr.size(); i < n - 1; ++i) {
      if (left[i] != INT_MAX && right[n - 1 - i - 1] != INT_MAX)
        minLen = min(minLen, left[i] + right[n - 1 - i - 1]);
    }
    return minLen == INT_MAX ? -1 : minLen;
  }
};
int main() {
  Solution sol;

  return 0;
}

