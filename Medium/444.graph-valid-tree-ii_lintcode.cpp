#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool status = true;
    int components = 0;
    unordered_map<int, int> parent;
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            ++components;
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
            --components;
        } else {
            status = false;
        }
    }

   public:
    /**
     * @param a: the node a
     * @param b: the node b
     * @return: nothing
     */
    void addEdge(int a, int b) {
        if (status == true)
            uni(a, b);
    }

    /**
     * @return: check whether these edges make up a valid tree
     */
    bool isValidTree() { return status && components == 1; }
};
int main() {
    Solution sol;

    return 0;
}

