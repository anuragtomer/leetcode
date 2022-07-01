#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> largeGroups;
        vector<int> currentGroup;
        for (int i = 0, n = s.size(); i < n;) {
            currentGroup = {i, i};
            ++i;
            while (i < n && s[i - 1] == s[i])
                ++i;
            currentGroup.back() = i - 1;
            if (currentGroup.back() - currentGroup.front() >= 2)
                largeGroups.push_back(currentGroup);
        }
        return largeGroups;
    }
};
int main() {
    Solution sol;

    return 0;
}

