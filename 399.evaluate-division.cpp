#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool dfs(vector<vector<double>> &edges, int source, int target, double &value, vector<bool> visited) {
        if (edges[source][target] != 0.0) {
            value *= edges[source][target];
            return true;
        }
        if (visited[source] == true)
            return false;
        visited[source] = true;
        for (int i = 0; i < edges[source].size(); ++i) {
            if (edges[source][i] != 0.0) {
                value *= edges[source][i];
                if (dfs(edges, i, target, value, visited))
                    return true;
                value /= edges[source][i];
            }
        }
        return false;
    }

   public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries) {
        unordered_map<string, int> idx;
        int i = 0;
        for (auto variable : equations) {
            if (idx.find(variable[0]) == idx.end()) {
                idx[variable[0]] = i++;
            }
            if (idx.find(variable[1]) == idx.end()) {
                idx[variable[1]] = i++;
            }
        }
        vector<vector<double>> edges(idx.size(), vector<double>(idx.size(), 0.0));
        for (int i = 0; i < values.size(); ++i) {
            string var1 = equations[i][0], var2 = equations[i][1];
            edges[idx[var1]][idx[var1]] = 1;
            edges[idx[var2]][idx[var2]] = 1;
            edges[idx[var1]][idx[var2]] = values[i];
            edges[idx[var2]][idx[var1]] = 1 / values[i];
        }
        vector<double> result;
        for (auto query : queries) {
            double value = 1.0;
            if (idx.find(query[0]) == idx.end() || idx.find(query[1]) == idx.end()) {
                result.push_back(-1.0);
                continue;
            }
            int i = idx[query[0]], j = idx[query[1]];

            vector<bool> visited(idx.size(), false);
            if (dfs(edges, i, j, value, visited))
                result.push_back(value);
            else
                result.push_back(-1.0);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

