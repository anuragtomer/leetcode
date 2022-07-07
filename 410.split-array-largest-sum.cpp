#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool doable(vector<int> &nums, int cuts, int maxAllowed) {
        int currentSum = 0;
        for (int num : nums) {
            if (num > maxAllowed)
                return false;
            else if (currentSum + num <= maxAllowed) {
                currentSum += num;
            } else {
                --cuts;
                currentSum = num;
                if (cuts < 0)
                    return false;
            }
        }
        return true;
    }

   public:
    int splitArray(vector<int> &nums, int m) {
        int left = INT_MIN, right = 0;
        for (auto num : nums) {
            left = max(left, num);
            right += num;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;

    return 0;
}

