#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> nextGreater;
        vector<int> result(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            while (!nextGreater.empty() && nums[nextGreater.top()] < nums[i]) {
                result[nextGreater.top()] = nums[i];
                nextGreater.pop();
            }
            nextGreater.push(i);
        }
        for (int i = 0; i < nums.size() && !nextGreater.empty() && nextGreater.top() != i; ++i) {
            while (!nextGreater.empty() && nums[nextGreater.top()] < nums[i]) {
                result[nextGreater.top()] = nums[i];
                nextGreater.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

