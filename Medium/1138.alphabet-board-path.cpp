#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string alphabetBoardPath(string target) {
        string board = "afkpuz";
        int row = 0, col = 0, drow = 0, dcol = 0;
        string output;
        for (char c : target) {
            if (c >= 'z') {
                drow = 5 - row;
                dcol = -col;
            } else if (c >= 'u') {
                drow = 4 - row;
                dcol = c - 'u' - col;
            } else if (c >= 'p') {
                drow = 3 - row;
                dcol = c - 'p' - col;
            } else if (c >= 'k') {
                drow = 2 - row;
                dcol = c - 'k' - col;
            } else if (c >= 'f') {
                drow = 1 - row;
                dcol = c - 'f' - col;
            } else {
                drow = -row;
                dcol = c - 'a' - col;
            }
            if (row == 5 && dcol != 0) {
                output.append("U");
                drow++;
                row--;
            }
            row += drow;
            col += dcol;
            if (dcol < 0)
                while (dcol != 0) {
                    output.append("L");
                    dcol++;
                }
            else
                while (dcol != 0) {
                    output.append("R");
                    dcol--;
                }
            if (drow < 0)
                while (drow != 0) {
                    output.append("U");
                    drow++;
                }
            else
                while (drow != 0) {
                    output.append("D");
                    drow--;
                }
            output.append("!");
        }
        return output;
    }
};

int main() {
    Solution sol;
    string target = "leet";
    string output = "RDD!RRRUU!!DDD!";
    assert(sol.alphabetBoardPath(target) == output);
    target = "code";
    output = "RR!RRDD!LUU!R!";
    assert(sol.alphabetBoardPath(target) == output);
    target = "zb";
    output = "DDDDD!URUUUU!";
    assert(sol.alphabetBoardPath(target) == output);
    return 0;
}
