#include "lib.h"


class Solution {
public:
    int search(vector <int>& nums, int target) {
        int lb = 0, ub = nums.size() - 1, mid, pivot;
         /* Find pivot point. */
        while(lb < ub) {
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
         /* Do normal binary search taking pivot point into consideration. */
        while(lb <= ub) {
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

int main(){
    Solution sol;
    int N;
    int target, val;
    vector <int> arr;
    arr.clear();
    cin >> N;
    while (N) {
        N--;
        cin >> val;
        arr.push_back(val);
    }
    cin >> target;
    cout << sol.search(arr, target);
    return 0;
}
