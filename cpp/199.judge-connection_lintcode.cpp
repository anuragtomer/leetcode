#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void floodFill(vector<vector<int>> &arr, int i, int j, int k) {
        if (i >= 0 && j >= 0 && i < arr.size() && j < arr[i].size() && arr[i][j] == k) {
            arr[i][j] = k - 1;
            floodFill(arr, i + 1, j, k);
            floodFill(arr, i - 1, j, k);
            floodFill(arr, i, j + 1, k);
            floodFill(arr, i, j - 1, k);
        }
    }

   public:
    /**
     * @param arr: the arr
     * @param k: the k
     * @return: if all instances of value k in arr are connected
     */
    bool judgeConnection(vector<vector<int>> &arr, int k) {
        int H = arr.size(), W = arr[0].size();
        bool foundOne = false;
        for (int i = 0; i < H && !foundOne; ++i) {
            for (int j = 0; j < W && !foundOne; ++j) {
                if (arr[i][j] == k) {
                    floodFill(arr, i, j, k);
                    foundOne = true;
                }
            }
        }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (arr[i][j] == k) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}

