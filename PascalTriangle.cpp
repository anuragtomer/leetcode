#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PascalTriangle(numRows);
        vector<int> one(1, 1);
        PascalTriangle[0] = vector<int>(1);
        PascalTriangle[0] = one; 
        for (int i = 1; i < numRows; i++) {
            vector<int> row(i+1, 0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    row[j] = 1;
                else
                    row[j] = PascalTriangle[i-1][j-1] + PascalTriangle[i-1][j];
            }
            PascalTriangle[i] = vector<int>(i+1);
            PascalTriangle[i] = row;
        }
        return PascalTriangle;
    }
};
int main() {
    Solution sol;
    int input;
    cin >> input;
    vector<vector<int>> output = sol.generate(input);
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


