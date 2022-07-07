#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void wiggleSort(vector<int> &nums) {
        if (nums.empty())
            return;
        bool greater = false;
        for (int i = 0; i < nums.size() - 1; ++i) {
            auto &curr = nums[i], &next = nums[i + 1];
            if (greater && curr < next)
                swap(curr, next);
            else if (!greater && curr > next)
                swap(curr, next);
            greater = !greater;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}

