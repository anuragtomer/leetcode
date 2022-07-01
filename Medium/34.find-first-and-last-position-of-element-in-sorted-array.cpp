#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /*
    int searchRecursiveLower(vector<int> nums, int lb, int ub, int target) {
        if (lb+1 >= ub) {
            // Stop when there are two elements. Give preference to lb.
            if (nums[lb] == target)
                return lb;
            else
                return ub;
        }
        int mid = lb + (ub - lb)/2;
        if (nums[mid] >= target)
            return searchRecursiveLower(nums, lb, mid, target);
        else
            return searchRecursiveLower(nums, mid+1, ub, target);
    }

    int searchRecursiveHigher(vector<int> nums, int lb, int ub, int target) {
        if (lb+1 >= ub) {
            // Stop when there are two elements. Give preference to ub.
            if (nums[ub] == target)
                return ub;
            else
                return lb;
        }
        int mid = lb + (ub - lb)/2;
        if (nums[mid] <= target)
            return searchRecursiveHigher(nums, mid, ub, target);
        else
            return searchRecursiveHigher(nums, lb, mid-1, target);
    }

    vector<int> searchRecursive(vector<int> &nums, int lb, int ub, int target) {
        if (lb > ub) {
            return {-1, -1};
        }
        int mid = lb + (ub - lb)/2;
        if (nums[mid] == target) {
            vector<int> output(2, -1);
            output[0] = searchRecursiveLower(nums, lb, mid, target);
            output[1] = searchRecursiveHigher(nums, mid, ub, target);
            return output;
        } else if (nums[mid] < target)
            return searchRecursive(nums, mid+1, ub, target);
        else
            return searchRecursive(nums, lb, mid-1, target);
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRecursive(nums, 0, nums.size() - 1, target);
    }
    */
    // Another solution using binary_search
    int first_pos(vector<int> &nums, int target) {
        int n = nums.size();
        int first = n;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                first = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return first;
    }

   public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int lower = first_pos(nums, target);
        int higher = first_pos(nums, target + 1) - 1;
        if (higher >= lower)
            return {lower, higher};
        else
            return {-1, -1};
    }
    // Another cool solution:
    /*vector<int> searchRange(vector<int>& ns, int t) {
        auto p = equal_range(ns.begin(),ns.end(),t);
        if (distance(p.first,p.second) > 0) {
            return {distance(ns.begin(),p.first), distance(ns.begin(), p.second)-1};
        } else {
            return {-1,-1};
        }
    }*/
};

int main(void) {
    Solution sol;
    int count = 0, total = 4;
    vector<int> output;
    std::vector<int> nums;
    nums = {1, 5, 5, 7, 7, 10};
    output = sol.searchRange(nums, 7);
    if (output[0] == 3 && output[1] == 4)
        count++;
    output = sol.searchRange(nums, 6);
    if (output[0] == -1 && output[1] == -1)
        count++;
    nums = {1, 2, 3, 3, 3, 3, 4, 5, 9};
    output = sol.searchRange(nums, 3);
    if (output[0] == 2 && output[1] == 5)
        count++;
    nums = {1};
    output = sol.searchRange(nums, 1);
    if (output[0] == 0 && output[1] == 0)
        count++;
    cout << count << "/" << total << " test cases passed.\n";
    return 0;
}
