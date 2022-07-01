#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    int components = 0;
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return parent[x];
    }
    bool uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            components--;
            parent[x] = y;
            return true;
        } else {
            return false;
        }
    }

   public:
    bool validTree(int n, vector<vector<int>> &edges) {
        parent = vector<int>(n);
        components = n;
        iota(parent.begin(), parent.end(), 0);
        for (auto edge : edges) {
            if (!uni(edge[0], edge[1]))
                return false;
        }
        return components == 1;
    }
};

int main() {
    Solution sol;

    return 0;
}

