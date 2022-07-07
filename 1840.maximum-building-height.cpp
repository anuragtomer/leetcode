#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxBuilding(int n, vector<vector<int>> &restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();

        for (int i = 1; i < m; ++i)
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        for (int i = m - 2; i >= 0; --i)
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);

        int result = 0, left, heightL, right, heightR;
        for (int i = 1; i < m; ++i) {
            left = restrictions[i - 1][0], right = restrictions[i][0];
            heightL = restrictions[i - 1][1], heightR = restrictions[i][1];
            // right - left:  Tells us how many height can we use.
            // right - left - abs(heightL - heightR):  means how many height we will be left with after increasing the
            //                                         lower one, to make them of same height.
            // (right - left - abs(heightL - heightR)) / 2:  means how many height we can get to increase these 2 bring
            //                                               them to same height.
            result = max(result, max(heightL, heightR) + (right - left - abs(heightL - heightR)) / 2);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> restrictions;
    restrictions = {{2, 1}, {4, 1}};
    assert(2 == sol.maxBuilding(5, restrictions));
    restrictions = {};
    assert(5 == sol.maxBuilding(6, restrictions));
    restrictions = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    assert(5 == sol.maxBuilding(10, restrictions));
    return 0;
}

