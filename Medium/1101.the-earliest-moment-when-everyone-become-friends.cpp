#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {

    int _find(int x, unordered_map<int, int> &parent) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = _find(parent[x], parent);
        }
        return parent[x];
    }

    void _union(int x, int y, unordered_map<int, int> &parent, int &components) {
        x = _find(x, parent);
        y = _find(y, parent);
        if (x != y) {
            parent[x] = y;
            components--;
        }
    }

   public:
    int minTime(vector<vector<int>> &logs, int n) {
        int components = n;
        unordered_map<int, int> parent;
        sort(begin(logs), end(logs), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        for (auto log : logs) {
            _union(log[1], log[2], parent, components);
            if (components == 1)
                return log[0];
        }
        if (components > 1)
            return -1;
        else
            return 0;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> logs = {{2, 0, 1}, {3, 1, 2}, {4, 2, 3}};
    assert(4 == sol.minTime(logs, 4));
    logs = {{2, 0, 1}, {3, 1, 2}};
    assert(-1 == sol.minTime(logs, 4));
    logs = {{2, 0, 1}, {3, 1, 2}, {1, 2, 3}, {1, 0, 3}};
    assert(sol.minTime(logs, 4) == 2);
    logs = {{2, 0, 1}, {1, 1, 2}, {1, 2, 3}};
    assert(sol.minTime(logs, 4) == 2);
    return 0;
}
