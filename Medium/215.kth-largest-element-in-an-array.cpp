#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
       int findKthLargest(vector<int>& nums, int k) {
       multiset<int> st;
       for (auto num: nums) {
       st.insert(num);
       if (st.size() > k)
       st.erase(st.begin());
       }
       return *st.begin();
       }
       */
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    assert(sol.findKthLargest(nums, k) == 5);
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    assert(sol.findKthLargest(nums, k) == 4);
    nums = {99, 99};
    k = 1;
    assert(sol.findKthLargest(nums, k) == 99);
    return 0;
}

