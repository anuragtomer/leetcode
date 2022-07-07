#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> avoidFlood(vector<int> &rains) {
        set<int> dryLakeDays;
        unordered_map<int, int> fillDay;
        vector<int> result(rains.size());
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                dryLakeDays.insert(i);
                result[i] = 1; // Some dummy no for now.
            } else {
                if (fillDay.find(rains[i]) != fillDay.end()) {
                    // This lake is full at the moment. Lets try to empty it.
                    auto it = dryLakeDays.lower_bound(fillDay[rains[i]]);
                    if (it == dryLakeDays.end())
                        return {};              // There is no no-rain day after this lake was filled up.
                    else {                      // We found a day when there was no rain after rains[i] lake was filled.
                        result[*it] = rains[i]; // We would empty rains[i] lake on *it day.
                        dryLakeDays.erase(it);  // Cannot empty any more lakes on it day.
                    }
                }
                result[i] = -1;
                fillDay[rains[i]] = i; // lake `rain[i]` was filled on ith day.
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> rains = {1, 2, 3, 4};
    vector<int> expected = {-1, -1, -1, -1};
    vector<int> result = sol.avoidFlood(rains);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    rains = {1, 2, 0, 0, 2, 1};
    expected = {-1, -1, 2, 1, -1, -1};
    result = sol.avoidFlood(rains);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    rains = {1, 2, 0, 1, 2};
    expected = {};
    result = sol.avoidFlood(rains);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    rains = {69, 0, 0, 0, 69};
    expected = {-1, 69, 1, 1, -1};
    result = sol.avoidFlood(rains);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    return 0;
}

