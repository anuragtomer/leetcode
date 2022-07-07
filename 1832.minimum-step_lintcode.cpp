#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumStep(vector<int> &colors) {
        int n = colors.size();
        unordered_map<int, int> minStep;
        unordered_set<int> visitedGrid;
        unordered_set<int> visitedColor;

        vector<vector<int>> colorGroup(n + 1);
        for (int i = 0; i < n; i++) {
            colorGroup[colors[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);
        minStep[0] = 0;
        visitedGrid.insert(0);

        while (!que.empty()) {
            int pos = que.front();
            que.pop();
            int color = colors[pos];
            if (!visitedColor.count(color)) {
                visitedColor.insert(color);
                for (int newPos : colorGroup[color]) {
                    if (isValid(n, newPos, visitedGrid)) {
                        minStep[newPos] = minStep[pos] + 1;
                        que.push(newPos);
                        visitedGrid.insert(newPos);
                    }
                }
            }
            int newPos = pos + 1;
            if (isValid(n, newPos, visitedGrid)) {
                minStep[newPos] = minStep[pos] + 1;
                que.push(newPos);
                visitedGrid.insert(newPos);
            }
            newPos = pos - 1;
            if (isValid(n, newPos, visitedGrid)) {
                minStep[newPos] = minStep[pos] + 1;
                que.push(newPos);
                visitedGrid.insert(newPos);
            }
        }
        return minStep[n - 1];
    }
    bool isValid(int n, int position, unordered_set<int> &visitedGrid) {
        if (position < 0 or position >= n) {
            return false;
        }
        if (visitedGrid.count(position)) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution sol;

    return 0;
}

