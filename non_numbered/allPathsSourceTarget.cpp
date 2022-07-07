#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        void pathExists(vector<vector<int>> graph, int curr_node, vector <int> path,
                   vector<vector<int>> &return_output) {
        if (curr_node == graph.size() - 1) {
            path.push_back(curr_node);
            return_output.push_back(path);
        }
        
        for (int i = 0; i < graph[curr_node].size(); i++) {
            path.push_back(curr_node);
            pathExists(graph, graph[curr_node][i], path, return_output);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <int> path;
        vector<vector<int>> return_output;
        return_output.clear();
        for (int i = 0; i < graph[0].size(); i++) {
            path.push_back(0);
            pathExists(graph, graph[0][i], path, return_output);
            path.pop_back();
        }
        return return_output;
    }

};
int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2}, {2,5}, {4,3}, {5}, {1}, {}};
    vector<vector<int>> output;
    output.clear();
    output = sol.allPathsSourceTarget(graph);
    for (vector <int> &paths: output) {
        cout << "Path 1: ";
        for (int node: paths) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}


