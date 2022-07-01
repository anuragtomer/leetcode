#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution{
    public:
        // Returns vector containing max values from each row.
        vector <int> maxRowVector(vector <vector <int> > & grid) {
            int max_val = INT_MIN;
            int maxRows = grid.size();
            int maxIndex = grid[0].size();
            vector <int> maxArray(maxRows);
            for (int index = 0; index < maxRows; index++) {
                max_val = INT_MIN;
                for (int i = 0; i < maxIndex; i++) {
                    if (max_val < grid[index][i]) {
                        max_val = grid[index][i];
                    }
                }
                maxArray[index] = max_val;
            }
            return maxArray;
        }
        // Returns vector containing max values from each column.
        vector <int> maxColVector(vector <vector <int> > &grid) {
            int max_val = INT_MIN;
            int maxCols = grid[0].size();
            int maxIndex = grid.size();
            vector <int> maxArray(maxCols);
            for (int index = 0; index < maxCols; index++) {
                max_val = INT_MIN;
                for (int i = 0; i < maxIndex; i++) {
                    if (max_val < grid[i][index]) {
                        max_val = grid[i][index];
                    }
                }
                maxArray[index] = max_val;
            }
            return maxArray;
         }

        // Returns min of a and b.
        int min(int a, int b) {
            return (a<b ? a : b);
        }

        // Returns the max increase in each of the building without affecting the skyline.
        int maxIncreaseKeepingSkyline(vector <vector <int> > &grid) {
            vector <int> RowVector = maxRowVector(grid);
            vector <int> ColVector = maxColVector(grid);
            for (int i = 0; i < RowVector.size(); i++) {
                cout << RowVector[i];
            }
            cout << endl;
            for (int i = 0; i < ColVector.size(); i++) {
                cout << ColVector[i];    
            }
            cout << endl;
            int count = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    count += min(RowVector[i], ColVector[j]) - grid[i][j];
                }
            }
            return count;
        }

};

int main() {
    Solution sol;
    vector <vector <int> > grid {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    int x = sol.maxIncreaseKeepingSkyline(grid);
    cout << x << endl;
    return 0;
}

