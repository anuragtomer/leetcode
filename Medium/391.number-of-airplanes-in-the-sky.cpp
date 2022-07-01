#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int calculateMaxNumber(vector<pair<int, int>> &flightTimes) {
        auto comp = [](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; };
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(flightTimes.begin(), flightTimes.end(),
             [](pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; });
        size_t max_len = 0;
        for (auto flight : flightTimes) {
            while (!pq.empty() && flight.first >= pq.top())
                pq.pop();

            pq.push(flight.second);
            max_len = max(max_len, pq.size());
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    return 0;
}

