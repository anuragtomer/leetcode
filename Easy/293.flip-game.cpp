#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> result;
        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string sCopy(s);
                sCopy[i] = '-';
                sCopy[i + 1] = '-';
                result.push_back(sCopy);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

