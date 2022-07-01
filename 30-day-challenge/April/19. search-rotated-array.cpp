#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int search(vector<int> &nums, int target) {
        int lb = 0, ub = nums.size() - 1, mid, pivot;
        while (lb < ub) {
            mid = (ub + lb) / 2;
            if (nums[mid] > nums[ub])
                lb = mid + 1;
            else
                ub = mid;
        }
        pivot = lb;
        lb = 0;
        ub = nums.size() - 1;
        int realmid;
        while (lb <= ub) {
            mid = (lb + ub) / 2;
            realmid = (mid + pivot) % nums.size();
            if (nums[realmid] == target)
                return realmid;
            else if (nums[realmid] < target) {
                lb = mid + 1;
            } else
                ub = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums2 = {0, 1, 2, 3, 4, 5, 6, 7};
    assert(0 == sol.search(nums2, 0));
    assert(3 == sol.search(nums2, 3));
    return 0;
}