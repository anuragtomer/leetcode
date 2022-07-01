#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkStraightLine(vector<vector<int>> &c) {
        int coSz = c.size();
        if (coSz == 2)
            return true;
        int area;
        for (int i = 2; i < coSz; ++i) {
            area = c[0][0] * (c[1][1] - c[i][1]) + c[1][0] * (c[i][1] - c[0][1]) + c[i][0] * (c[0][1] - c[1][1]);
            if (area != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    assert(true == sol.checkStraightLine(coordinates));
    coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    assert(false == sol.checkStraightLine(coordinates));
    return 0;
}
