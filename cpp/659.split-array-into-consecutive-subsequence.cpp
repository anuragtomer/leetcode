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
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> remaining, end;
    for (int num : nums) {
      remaining[num]++;
    }
    for (int num : nums) {
      if (remaining[num] == 0) // I have consumed all occurrances of num.
        continue;
      remaining[num]--; // Consuming this occurance
      if (end[num - 1] > 0) {
        // If there is something ending at previous location, end it here.
        end[num - 1]--;
        end[num]++;
      } else if (remaining[num + 1] > 0 && remaining[num + 2] > 0) {
        // If there are 2 more consecutive nums, consume them too.
        remaining[num + 1]--;
        remaining[num + 2]--;
        end[num + 2]++;
      } else {
        // Can't increase an earlier sequence, neither can I make a sequence with next nums
        return false;
      }
    }
    return true;
  }
};
