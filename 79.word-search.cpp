#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool foundCompleteWord(vector<vector<char>> &board, int x, int y, string word, int index, int H, int W) {
        if (index == word.size())
            return true;
        if (x < 0 || y < 0 || x >= H || y >= W || board[x][y] != word[index])
            return false;
        char c = board[x][y];
        board[x][y] = '#';
        bool found = (foundCompleteWord(board, x + 1, y, word, index + 1, H, W) ||
                      foundCompleteWord(board, x - 1, y, word, index + 1, H, W) ||
                      foundCompleteWord(board, x, y + 1, word, index + 1, H, W) ||
                      foundCompleteWord(board, x, y - 1, word, index + 1, H, W));
        board[x][y] = c;
        return found;
    }

   public:
    bool exist(vector<vector<char>> &board, string word) {
        int H = board.size();
        if (H == 0)
            return word.empty();
        int W = board[0].size();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (foundCompleteWord(board, i, j, word, 0, H, W)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}

