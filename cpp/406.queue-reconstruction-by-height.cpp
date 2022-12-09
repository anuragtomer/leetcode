#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] > b[0] || ((a[0] == b[0]) && (a[1] < b[1])); });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> res = sol.reconstructQueue(people);
    for (auto p : res) {
        cout << "(" << p[0] << ", " << p[1] << "), ";
    }
    return 0;
}