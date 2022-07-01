#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> greaterNum;
        stack<int> greater;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!greater.empty() && nums2[greater.top()] < nums2[i]) {
                greaterNum[nums2[greater.top()]] = nums2[i];
                greater.pop();
            }
            greater.push(i);
        }
        vector<int> result;
        for (auto num : nums1) {
            if (greaterNum.find(num) != greaterNum.end()) {
                result.push_back(greaterNum[num]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;

    return 0;
}

