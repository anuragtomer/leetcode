#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        priority_queue<double, vector<double>, greater<>> pq;
        for (int i = 0; i < dist.size(); ++i)
            pq.push((1.0 * dist[i]) / (1.0 * speed[i]));
        int time = 0;
        while (!pq.empty()) {
            if (pq.top() > time)
                pq.pop();
            else
                return time;
            ++time;
        }
        return time;
    }
};
int main() {
    Solution sol;

    return 0;
}

