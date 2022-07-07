#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        for (int num: nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 4, 5, 6, 1, 5, 6};
    if (4 == sol.singleNumber(nums)) {
        cout << "Test case passed";
    }
    return 0;
}