/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
/* Both functions work.
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [] (vector<int> p1, vector<int> p2) {
                      return (sqrt(p1[0]*p1[0] + p1[1]*p1[1]) >= sqrt(p2[0]*p2[0] + p2[1]*p2[1]));
                      };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> heap(comp);
        for (auto point: points) {
            heap.push(point);
        }
        points.clear();
        for (int i = 0; i < K; i++) {
            vector<int> tp = heap.top();
            heap.pop();
            points.push_back(tp);
        }
        return points;
    } */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [] (vector<int> p1, vector<int> p2) {
                      return (sqrt(p1[0]*p1[0] + p1[1]*p1[1]) >= sqrt(p2[0]*p2[0] + p2[1]*p2[1]));
                      };
        make_heap(points.begin(), points.end(), comp);
        vector<vector<int>> output;
        for (int i = 0; i < K; i++) {
            pop_heap(points.begin(), points.end(), comp);
            vector<int> tp = points.back();
            points.pop_back();
            output.push_back(tp);
        }
        return output;
    }
};

// @lc code=end

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];
    int k;
    cin >> k;
    Solution sol;
    points = sol.kClosest(points, k);
    for (auto p: points)
        cout << p[0] << " " << p[1] << "\n";
    return 0;
}