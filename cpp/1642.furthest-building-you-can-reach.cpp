#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.push(-diff);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return n - 1;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    assert(4 == sol.furthestBuilding(heights, 5, 1));
    return 0;
}

