#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    // Another way of doing the same without maps.
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<pair<int, int>> peoples(N + 1);
        for (auto t : trust) {
            peoples[t[0]].first++;  // this guy might be a judge
            peoples[t[1]].second++; // this guy might be trusting everyone. trust counter.
        }

        for (auto i = 1; i <= N; i++) {
            auto p = peoples[i];
            if (p.first == 0 && p.second == N - 1)
                return i;
        }
        return -1;
    }
    /*
    int findJudge(int N, vector<vector<int>> &trust) {
        if (N == 1 && trust.empty())
            return 1;
        unordered_map<int, unordered_set<int>> peopletrust;
        unordered_map<int, unordered_set<int>> maybejudge;
        for (auto people : trust) {
            peopletrust[people[0]].insert(people[1]);
            maybejudge[people[1]].insert(people[0]);
        }
        for (auto judges : maybejudge) {
            if (judges.second.size() == N - 1 && peopletrust[judges.first].empty()) {
                return judges.first;
            }
        }
        return -1;
    }*/
};

int main() {
    Solution sol;
    vector<vector<int>> trust = {{1, 2}};
    assert(2 == sol.findJudge(2, trust));

    trust = {{1, 3}, {2, 3}};
    assert(3 == sol.findJudge(3, trust));

    trust = {{1, 3}, {2, 3}, {3, 1}};
    assert(-1 == sol.findJudge(3, trust));

    trust = {{1, 2}, {2, 3}};
    assert(-1 == sol.findJudge(3, trust));

    trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    assert(3 == sol.findJudge(4, trust));
    return 0;
}
