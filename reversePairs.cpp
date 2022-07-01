#include <iostream>

using namespace std;

class Solution{
    public:
int count_half(vector <int> nums, int lower, int higher, int num) {
        if (lower > higher)
            return 0;
        if (lower == higher)
            if (nums[lower]/2 > num)
                return 1;
            else 
                return 0;
        else
            return count_half(nums, lower, (lower + higher)/2, num) + count_half(nums, ((lower + higher)/2) + 1, higher, nums);
        
    }
    int reversePairs(vector<int>& nums) {
        // int count = 0;
        // for (int i = 0; i < nums.size(); i ++){
        //     if (i > LONG_MAX / 2)
        //         continue;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         //if (nums[j] > LONG_MAX / 2)
        //         //    continue;
        //         if ((nums[i]/2.0) > (float)nums[j])
        //             count++;
        //     }
        // }
        // return count;
        int count = 0;
        if (nums.size() > 2) {
            for (int i = nums.size() - 1; i >= 0; i ++)
                count += count_half(nums, 0, nums.size()/2, nums[i]) + count_half(nums, (nums.size()/2) + 1, nums.size() - 2, nums[i]);
        }
    }
};

int main()
{
    Solution sol;
    
    return 0;
}

