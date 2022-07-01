#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    float length(int x1, int y1, int x2, int y2) { return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5); }

   public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            auto query = queries[i];
            for (auto point : points) {
                if (length(point[0], point[1], query[0], query[1]) <= static_cast<float>(query[2]))
                    result[i]++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {3, 3}, {5, 3}, {2, 2}}, queries = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    vector<int> expected = {3, 2, 2};
    vector<int> result = sol.countPoints(points, queries);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    return 0;
}

