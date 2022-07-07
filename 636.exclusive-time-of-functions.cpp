#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    struct log {
        int id;
        string op;
        int time;
    };

   public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> times(n, 0);
        stack<log> st;
        for (auto entry : logs) {
            stringstream ss(entry);
            array<string, 3> logEntry;
            getline(ss, logEntry[0], ':');
            getline(ss, logEntry[1], ':');
            getline(ss, logEntry[2], ':');
            log item = {stoi(logEntry[0]), logEntry[1], stoi(logEntry[2])};
            if (item.op == "start") {
                st.push(item);
            } else {
                int duration = item.time - st.top().time + 1;
                times[item.id] += duration;
                st.pop();
                if (!st.empty()) {
                    times[st.top().id] -= duration;
                }
            }
        }
        return times;
    }
};

int main() {
    Solution sol;

    return 0;
}

