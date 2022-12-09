#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      vector<int> temp;
      for (int i = nums.size() - 1, j = 0; j < k; --i, ++j)
        temp.push_back(nums[i]);
      int last = nums.back();
      for (int i = nums.size() - 1 - k; i >= 0; --i)
        nums[i+k] = nums[i];
      for (int i = 0; i < temp.size(); ++i) {
        nums[temp.size() - 1 - i] = temp[i];
      }
    }*/
    /*
    void rotate(vector<int> &nums, int k) {
        int start = 0, elementsDone = 0;
        int n = nums.size();
        k = k % n;
        while (elementsDone < n) {
            int curr = start;
            int temp = nums[start];
            do {
                ++elementsDone;
                nums[start] = nums[(start - k + n) % n];
                start = (start - k + n) % n;
            } while (start != curr);
            nums[(start + k) % n] = temp;
            ++start;
        }
    }
    */
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
int main() {
    Solution sol;

    return 0;
}

