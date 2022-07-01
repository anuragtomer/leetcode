#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> result;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            groups[groupSizes[i]].push_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
        }
        for (auto group : groups) {
            assert(group.second.empty());
        }
        return result;
    }
};

void printGroups(const vector<vector<int>> &groups) {
    for (auto group : groups) {
        cout << "[";
        for (auto people : group) {
            cout << people << " ";
        }
        cout << "]\n";
    }
}
int main() {
    Solution sol;
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    printGroups(sol.groupThePeople(groupSizes));
    groupSizes = {2, 1, 3, 3, 3, 2};
    printGroups(sol.groupThePeople(groupSizes));
    return 0;
}
