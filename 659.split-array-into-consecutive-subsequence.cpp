/*class Solution {
public:
  bool isPossible(vector<int>& nums) {
    vector<vector<int>> sets;
    bool inserted;
    for (int i = 0, n = nums.size(); i < n; ++i) {
      inserted = false;
      for (int j = sets.size() - 1; j >= 0 && not inserted; --j) {
        if (sets[j].back() + 1 == nums[i]) {
          sets[j].push_back(nums[i]);
          inserted = true;
        }
      }
      if (not inserted) {
        sets.push_back({nums[i]});
      }
    }
    for (int i = 0, k = sets.size(); i < k; ++i) {
      if (sets[i].size() < 3)
        return false;
    }
    return true;
  }
};*/
class Solution {
 public:
  bool isPossible(vector<int> &A) {
    unordered_map<int, int> left, end;
    for (int i : A) {
      left[i]++;
    }
    for (int i : A) {
      if (left[i] == 0)
        continue;
      left[i]--;
      if (end[i - 1] > 0) {
        end[i - 1]--;
        end[i]++;
      } else if (left[i + 1] > 0 && left[i + 2] > 0) {
        left[i + 1]--;
        left[i + 2]--;
        end[i + 2]++;
      } else {
        return false;
      }
    }
    return true;
  }
};
