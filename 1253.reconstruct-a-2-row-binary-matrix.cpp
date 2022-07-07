#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
        vector<vector<int>> matrix(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); ++i) {
            if (colsum[i] == 2) {
                matrix[0][i] = 1;
                matrix[1][i] = 1;
                --lower;
                --upper;
            } else if (colsum[i] == 1) {
                if (upper > lower) {
                    matrix[0][i] = 1;
                    --upper;
                } else {
                    matrix[1][i] = 1;
                    --lower;
                }
            }
            if (upper < 0 || lower < 0)
                return vector<vector<int>>();
        }
        return (lower == 0 && upper == 0) ? matrix : vector<vector<int>>();
    }
};

int main() {
    Solution sol;
    vector<int> colsum = {1, 1, 1};
    vector<vector<int>> result = {{1, 0, 1}, {0, 1, 0}};
    vector<vector<int>> output = sol.reconstructMatrix(2, 1, colsum);
    auto check = [&]() {
        assert(result.size() == output.size());
        if (result.size() == 2) {
            assert(result[0].size() == output[0].size());
            assert(result[1].size() == output[1].size());
            for (int i = 0; i < result[0].size(); ++i) {
                assert(result[0][i] == output[0][i]);
            }
            for (int i = 0; i < result[1].size(); ++i) {
                assert(result[1][i] == output[1][i]);
            }
        }
    };
    cout << "Testing.." << endl;
    check();
    cout << "Passed" << endl;
    result = {};
    colsum = {2, 2, 1, 1};
    output = sol.reconstructMatrix(2, 3, colsum);
    cout << "Testing.." << endl;
    check();
    cout << "Passed" << endl;
    colsum = {2, 1, 2, 0, 1, 0, 1, 2, 0, 1};
    result = {{1, 0, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 1, 0, 0}};
    output = sol.reconstructMatrix(5, 5, colsum);
    cout << "Testing.." << endl;
    check();
    cout << "Passed" << endl;
    return 0;
}

