#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* With extra space
 vector<int> spiralOrder(vector<vector<int>> &matrix) {
     vector<int> result;
     vector<vector<int>> visited = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), false));
     bool left = false, right = true, up = false, down = false;
     int i = 0, j = 0;
     while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size() && visited[i][j] == false) {
         visited[i][j] = true;
         result.push_back(matrix[i][j]);
         if (right == true && (((j + 1) == visited[i].size()) || visited[i][j + 1] == true)) {
             // I can't go right. Move down
             if (i < matrix.size() - 1 && visited[i + 1][j] == false) // Can I go down?
                 down = true;
             right = false;
         } else if (down == true && (((i + 1) == visited.size()) || visited[i + 1][j] == true)) {
             // Can't go any more down. Move left
             if (j > 0 && visited[i][j - 1] == false) // can I go left?
                 left = true;
             down = false;
         } else if (left == true && ((j == 0 || visited[i][j - 1] == true))) {
             if (i > 0 && visited[i - 1][j] == false) // Can I go up?
                 up = true;
             left = false;
         } else if (up == true && (i == 0 || visited[i - 1][j] == true)) {
             // Can't go up anymore. Try going right.
             up = false;
             if (j < matrix[i].size() - 1 && visited[i][j + 1] == false)
                 right = true;
         }
         if (up)
             i--;
         if (down)
             i++;
         if (left)
             j--;
         if (right)
             j++;
     }
     return result;
 }
 */
    // Without extra space
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int ilb = 1, iub = matrix.size() - 1, jlb = 0, jub = matrix[0].size() - 1;
        bool left = false, right = true, up = false, down = false;
        int i = 0, j = 0;
        int mn = matrix.size() * matrix[0].size();
        result.reserve(mn);
        while (result.size() != mn) {
            result.push_back(matrix[i][j]);
            if (right) {
                if (j == jub) {
                    down = true;
                    right = false;
                    jub--;
                }
            } else if (down) {
                if (i == iub) {
                    left = true;
                    down = false;
                    iub--;
                }
            } else if (left) {
                if (j == jlb) {
                    up = true;
                    left = false;
                    jlb++;
                }
            } else if (up) {
                if (i == ilb) {
                    up = false;
                    right = true;
                    ilb++;
                }
            }
            if (right)
                j++;
            if (down)
                i++;
            if (left)
                j--;
            if (up)
                i--;
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

