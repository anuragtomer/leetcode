#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {
    void visit(string airport, unordered_map<string, set<string>> &routes, vector<string> &result) {
        while (!routes[airport].empty()) {
            string next = *(routes[airport].begin());
            routes[airport].erase(routes[airport].begin());
            visit(next, routes, result);
        }
        result.push_back(airport);
    }

   public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> result;
        unordered_map<string, set<string>> routes;
        for (auto ticket : tickets)
            routes[ticket[0]].insert(ticket[1]);

        visit("JFK", routes, result);
        return vector<string>(result.rbegin(), result.rend());
    }
};
int main() {
    Solution sol;
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> output = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    vector<string> expected = sol.findItinerary(tickets);
    assert(true == testResp(output, expected));

    tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    output = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    expected = sol.findItinerary(tickets);
    assert(true == testResp(output, expected));

    tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    expected = {"JFK", "NRT", "JFK", "KUL"};
    output = sol.findItinerary(tickets);
    assert(true == testResp(output, expected));

    return 0;
}
