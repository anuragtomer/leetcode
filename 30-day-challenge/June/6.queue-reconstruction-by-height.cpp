#include <iostream>
#include <vector>
#include "../../include/utility.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<vector<int>> output;
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1]; // Maintain order if the heights are same.
            return a[0] > b[0];     // Sort by highest first.
        });
        // Start pushing each element at ith location.
        for (auto pp : people) {
            output.insert(output.begin() + pp[1], pp);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> output = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    vector<vector<int>> result = sol.reconstructQueue(people);
    testResp(output, result);
    return 0;
}
