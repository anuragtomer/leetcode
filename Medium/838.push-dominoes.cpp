#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    string pushDominoes(string dominoes) {
        queue<int> right, left;
        int n = dominoes.size();
        for (int i = 0; i < n; ++i) {
            char ch = dominoes[i];
            if (ch == 'R') {
                if (i + 1 < n && dominoes[i + 1] == '.')
                    right.push(i + 1);
            } else if (ch == 'L') {
                if (i > 0 && dominoes[i - 1] == '.')
                    left.push(i - 1);
            }
        }
        while (!left.empty() || !right.empty()) {
            int leftN = left.size();
            while (leftN) {
                --leftN;
                int i = left.front();
                left.pop();
                if (dominoes[i] == '.') {
                    dominoes[i] = 'L';
                    if (i > 0 && dominoes[i - 1] == '.')
                        left.push(i - 1);
                } else {
                    // Don't do anything.
                }
            }
            int rightN = right.size();
            while (rightN) {
                --rightN;
                int i = right.front();
                right.pop();
                if (dominoes[i] == 'L')
                    dominoes[i] = '.';
                else {
                    dominoes[i] = 'R';
                    if (i + 1 < n && dominoes[i + 1] == '.')
                        right.push(i + 1);
                }
            }
        }
        return dominoes;
    }
};

int main() {
    Solution sol;
    assert("LL.RR.LLRRLL.." == sol.pushDominoes(".L.R...LR..L.."));
    return 0;
}

