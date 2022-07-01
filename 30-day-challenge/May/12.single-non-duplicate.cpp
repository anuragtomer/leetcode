#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
    * Iterative
    * 
    * @param nums 
    * @return int 
    */
    /*
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                if (nums[mid] == nums[mid + 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return nums[low];
    }*/
    /**
     * Recursize
     * 
     * @param nums 
     * @return int 
     */
    int singleNonDuplicate(vector<int> &nums) {
        // cout << nums.size() << "\t";
        assert(nums.size() % 2 == 1);
        if (nums.size() == 1)
            return nums[0];
        int mid = (nums.size() - 1) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            return nums[mid];
        vector<int> newVec;
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid - 1])
                newVec = vector<int>(nums.begin(), nums.begin() + mid + 1);
            else
                newVec = vector<int>(nums.begin() + mid, nums.end());
        } else {
            if (nums[mid] == nums[mid - 1])
                newVec = vector<int>(nums.begin() + mid + 1, nums.end());
            else
                newVec = vector<int>(nums.begin(), nums.begin() + mid);
        }
        return singleNonDuplicate(newVec);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    assert(2 == sol.singleNonDuplicate(nums));
    nums = {3, 3, 7, 7, 10, 11, 11};
    assert(10 == sol.singleNonDuplicate(nums));
    nums = {1, 1, 2, 2, 3};
    assert(3 == sol.singleNonDuplicate(nums));
    return 0;
}
