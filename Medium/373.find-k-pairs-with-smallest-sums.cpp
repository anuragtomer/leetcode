#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&](vector<int> &a, vector<int> &b) {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        minHeap.push({0, 0});
        while (k > 0 && !minHeap.empty()) {
            --k;
            vector<int> top = minHeap.top();
            int i = top[0], j = top[1];
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size())
                minHeap.push({i + 1, j});
            if (i == 0 && j + 1 < nums2.size())
                minHeap.push({i, j + 1});
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

