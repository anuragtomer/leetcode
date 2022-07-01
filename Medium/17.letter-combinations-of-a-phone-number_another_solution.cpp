#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void pushToNext(string ch, vector<string> &nextcombos, const vector<string> &combos) {
        if (combos.empty()) {
            nextcombos.push_back(ch);
            return;
        }
        for (auto partial : combos) {
            partial += ch;
            nextcombos.push_back(partial);
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> combos, nextcombos;
        for (auto num : digits) {
            int curr = num - '0';
            switch (curr) {
                case 2:
                    pushToNext("a", nextcombos, combos);
                    pushToNext("b", nextcombos, combos);
                    pushToNext("c", nextcombos, combos);
                    break;
                case 3:
                    pushToNext("d", nextcombos, combos);
                    pushToNext("e", nextcombos, combos);
                    pushToNext("f", nextcombos, combos);
                    break;
                case 4:
                    pushToNext("g", nextcombos, combos);
                    pushToNext("h", nextcombos, combos);
                    pushToNext("i", nextcombos, combos);
                    break;
                case 5:
                    pushToNext("j", nextcombos, combos);
                    pushToNext("k", nextcombos, combos);
                    pushToNext("l", nextcombos, combos);
                    break;
                case 6:
                    pushToNext("m", nextcombos, combos);
                    pushToNext("n", nextcombos, combos);
                    pushToNext("o", nextcombos, combos);
                    break;
                case 7:
                    pushToNext("p", nextcombos, combos);
                    pushToNext("q", nextcombos, combos);
                    pushToNext("r", nextcombos, combos);
                    pushToNext("s", nextcombos, combos);
                    break;
                case 8:
                    pushToNext("t", nextcombos, combos);
                    pushToNext("u", nextcombos, combos);
                    pushToNext("v", nextcombos, combos);
                    break;
                case 9:
                    pushToNext("w", nextcombos, combos);
                    pushToNext("x", nextcombos, combos);
                    pushToNext("y", nextcombos, combos);
                    pushToNext("z", nextcombos, combos);
                    break;
                default:
                    break;
            }
            combos = nextcombos;
            nextcombos.clear();
        }
        return combos;
    }
};
int main() {
    Solution sol;
    string digits = "23";
    vector<string> output = sol.letterCombinations(digits);
    for (auto str : output)
        cout << str << " ";
    cout << endl;
    return 0;
}

