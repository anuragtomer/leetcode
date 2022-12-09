#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int binarySearch(vector<int> &row, int start, int end) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (row[mid] == 1) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

   public:
    /**
     * @param arr: The 2-dimension array
     * @return: Return the column the leftmost one is located
     */
    int getColumn(vector<vector<int>> &nums) {
        if (nums.size() == 0)
            return -1;
        int leftMost = nums[0].size() - 1;
        bool found1 = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i].back() == 0) // No 1's in this row. Skip over it.
                continue;
            found1 = true;
            leftMost = min(leftMost, binarySearch(nums[i], 0, leftMost));
            if (leftMost == 0) // Quick exit. I've reached first column, return.
                return 0;
        }
        return found1 ? leftMost : -1;
    }
};
int main() {
    Solution sol;

    return 0;
}

