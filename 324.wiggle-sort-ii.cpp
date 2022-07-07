#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {

   public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1)
            return;
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        int gE = 1, sE = (((n % 2) == 0) ? (n - 2) : (n - 1));
        int c = 0;
        while (c < n) {
            if (nums[c] < mid && ((c < sE) || ((c % 2) != 0))) {
                swap(nums[c], nums[sE]);
                sE -= 2;
            } else if (nums[c] > mid && ((c > gE) || ((c % 2) == 0))) {
                swap(nums[c], nums[gE]);
                gE += 2;
            } else
                c++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    sol.wiggleSort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    nums = {5, 3, 1, 2, 6, 7, 8, 5, 5};
    sol.wiggleSort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}