#include <iostream>

using namespace std;

class Solution{
    public:
        void goToNextElement(vector<vector<int>> graph, int node, vector<int> tillNowPath, vector<vector<int>> &result) {
            if (node == graph.size() - 1) {
                result.push_back(tillNowPath);
                return;
            } else {
                for (int i :graph[node]) {
                    tillNowPath.push_back(i);
                    goToNextElement(graph, i, tillNowPath, result);
                    tillNowPath.pop_back();
                }
            }
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> result;
            vector<int> tillNowPath;
            for (int i:graph[0]) {
                tillNowPath.push_back(i);
                goToNextElement(graph, i, tillNowPath, result);
                tillNowPath.pop_back();
            }
        }
};
int main() {
    Solution sol;
    
    return 0;
}


