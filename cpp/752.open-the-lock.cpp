#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int openLock(vector<string> &deadends, string target) {
        queue<string> bfs;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end())
            return -1;
        int depth = 0;
        bfs.push("0000");
        dead.insert("0000");
        while (!bfs.empty()) {
            int len = bfs.size();
            while (len) {
                --len;
                string current = bfs.front();
                bfs.pop();
                if (current == target)
                    return depth;
                for (int i = 0; i < 4; ++i) {
                    char temp = current[i];
                    current[i] = temp == '9' ? '0' : temp + 1;
                    if (dead.find(current) == dead.end()) {
                        bfs.push(current);
                        dead.insert(current);
                    }
                    current[i] = temp == '0' ? '9' : temp - 1;
                    if (dead.find(current) == dead.end()) {
                        bfs.push(current);
                        dead.insert(current);
                    }
                    current[i] = temp;
                }
            }
            depth++;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}

