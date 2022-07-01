#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        int rowMin = m, colMin = n;
        for (auto op : ops) {
            rowMin = min(rowMin, op[0]);
            colMin = min(colMin, op[1]);
        }
        return rowMin * colMin;
    }
};

int main() {
    Solution sol;

    return 0;
}

