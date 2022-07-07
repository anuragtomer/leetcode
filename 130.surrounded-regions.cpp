#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void checkAndChange(vector<vector<char>> &board, int i, int j) {
        board[i][j] = 'N';
        if (i != 0) {
            if (board[i - 1][j] == 'O') {
                checkAndChange(board, i - 1, j);
            }
        }
        if (i != board.size() - 1) {
            if (board[i + 1][j] == 'O') {
                checkAndChange(board, i + 1, j);
            }
        }
        if (j != 0) {
            if (board[i][j - 1] == 'O') {
                checkAndChange(board, i, j - 1);
            }
        }
        if (j != board[i].size() - 1) {
            if (board[i][j + 1] == 'O') {
                checkAndChange(board, i, j + 1);
            }
        }
    }

   public:
    void solve(vector<vector<char>> &board) {
        int H = board.size();
        if (H == 0)
            return;
        int W = board[0].size();
        for (int i = 0; i < H; ++i) {
            if (board[i][0] == 'O')
                checkAndChange(board, i, 0);
            if (board[i][W - 1] == 'O')
                checkAndChange(board, i, W - 1);
        }
        for (int j = 0; j < W; ++j) {
            if (board[0][j] == 'O')
                checkAndChange(board, 0, j);
            if (board[H - 1][j] == 'O')
                checkAndChange(board, H - 1, j);
        }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'N')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    vector<vector<char>> expected = {
        {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};
    sol.solve(board);
    assert(board.size() == expected.size());
    for (int i = 0; i < board.size(); ++i) {
        assert(board[i].size() == expected[i].size());
        for (int j = 0; j < board[i].size(); ++j) {
            assert(board[i][j] == expected[i][j]);
        }
    }
    return 0;
}
