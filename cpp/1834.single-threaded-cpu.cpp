#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    typedef pair<int, int> T;

   public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        int i = 0;
        for (auto &task : tasks)
            task.push_back(i++);
        sort(tasks.begin(), tasks.end());
        i = 0;
        int n = tasks.size();
        long currentTime = 0;
        vector<int> result;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                currentTime = max(currentTime, static_cast<long>(tasks[i][0]));
            }
            while (i < n && tasks[i][0] <= currentTime) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto [processingTime, index] = pq.top();
            pq.pop();
            currentTime += processingTime;
            result.push_back(index);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    vector<int> result = {0, 2, 3, 1};
    vector<int> output = sol.getOrder(tasks);
    auto check = [&]() {
        assert(result.size() == output.size());
        for (int i = 0; i < result.size(); ++i)
            assert(result[i] == output[i]);
    };
    cout << "Testing 1" << endl;
    check();
    cout << "PASSED" << endl;
    tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
    result = {4, 3, 2, 0, 1};
    output = sol.getOrder(tasks);
    cout << "Testing 2" << endl;
    check();
    cout << "PASSED" << endl;
    return 0;
}

