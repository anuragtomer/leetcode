#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include "../../include/utility.h"
using namespace std;

class Solution {

    /* 
    struct comp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
        }
    };
    */
   public:
    /* Another pretty cool solution based on pivoting. */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    /* vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> min_queue;
        for (auto point : points) {
            min_queue.push(make_pair(point[0], point[1]));
        }
        for (int i = 0; i < K; ++i) {
            pair<int, int> minimum = min_queue.top();
            min_queue.pop();
            result.push_back({minimum.first, minimum.second});
        }
        return result;
    } */
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> result = sol.kClosest(points, k);
    vector<vector<int>> expected = {{-2, 2}};
    testResp(result, expected);
    points = {{3, 3}, {5, -1}, {-2, 4}};
    k = 2;
    expected = {{3, 3}, {-2, 4}};
    result = sol.kClosest(points, k);
    testResp(result, expected);
    return 0;
}
