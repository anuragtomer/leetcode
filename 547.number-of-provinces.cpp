#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int provinces = 0;
    unordered_map<int, int> parent;
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            ++provinces;
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
            parent[x] = y;
            --provinces;
        }
    }

   public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int H = isConnected.size();
        if (H == 0)
            return 0;
        int W = isConnected[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (isConnected[i][j] == 1)
                    uni(i, j);
            }
        }
        return provinces;
    }
};

int main() {
    Solution sol;

    return 0;
}

