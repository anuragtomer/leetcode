#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canReach(vector<int> &arr, int start) {
        queue<int> bfsQ;
        vector<bool> visited(arr.size(), false);
        bfsQ.push(start);
        while (!bfsQ.empty()) {
            auto top = bfsQ.front();
            if (arr[top] == 0)
                return true;
            bfsQ.pop();
            visited[top] = true;
            if (top + arr[top] < arr.size() && !visited[top + arr[top]]) {
                bfsQ.push(top + arr[top]);
            }
            if (top - arr[top] >= 0 && !visited[top - arr[top]])
                bfsQ.push(top - arr[top]);
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}

