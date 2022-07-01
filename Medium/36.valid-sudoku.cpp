#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool checkRow(vector<vector<char>> &board, int i, int j) {
        for (int k = 0; k < 9; ++k) {
            if (j == k)
                continue;
            if (board[i][j] == board[i][k]) {
                return false;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>> &board, int i, int j) {
        for (int k = 0; k < 9; ++k) {
            if (i == k)
                continue;
            if (board[i][j] == board[k][j]) {
                return false;
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>> &board, int i, int j, int istart, int jstart) {
        for (int k = istart * 3; k < (istart)*3 + 3; ++k) {
            for (int l = jstart * 3; l < (jstart)*3 + 3; ++l) {
                if (i == k && j == l)
                    continue;
                if (board[i][j] == board[k][l]) {
                    return false;
                }
            }
        }
        return true;
    }

   public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' &&
                    (!checkRow(board, i, j) || !checkCol(board, i, j) || !checkBox(board, i, j, i / 3, j / 3)))
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;

    return 0;
}

