#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    int islandCount = 0;
    unordered_map<int, int> parent;
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            ++islandCount;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            --islandCount;
            parent[x] = y;
        }
    }

   public:
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        vector<int> result;
        for (auto point : operators) {
            int x = point.x, y = point.y;
            matrix[x][y] = 1;
            find((x * m) + y);
            if (x - 1 >= 0 && matrix[x - 1][y] == 1)
                uni((x * m) + y, ((x - 1) * m) + y);
            if (x + 1 < n && matrix[x + 1][y] == 1)
                uni((x * m) + y, ((x + 1) * m) + y);
            if (y - 1 >= 0 && matrix[x][y - 1] == 1)
                uni((x * m) + y, (x * m) + y - 1);
            if (y + 1 < m && matrix[x][y + 1] == 1)
                uni((x * m) + y, (x * m) + y + 1);
            result.push_back(islandCount);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

