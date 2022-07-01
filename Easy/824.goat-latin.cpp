#include <iostream>
#include <vector>
#include "../include/utility.h"
using namespace std;

class Solution {

   public:
    string toGoatLatin(string S) {
        vector<string> str = tokenize(S, ' ');
        string maa = "maa";
        for (string &s : str) {
            if (!isvowel(s[0])) {
                s.push_back(s.front());
                s.erase(0, 1);
            }
            s.append(maa);
            maa.push_back('a');
        }
        S = join(str, ' ');
        return S;
    }
};

int main() {
    Solution sol;
    string S = "I speak Goat Latin";
    string expected = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
    assert(sol.toGoatLatin(S).compare(expected) == 0);
    S = "The quick brown fox jumped over the lazy dog";
    expected =
        "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
    assert(expected == sol.toGoatLatin(S));
    return 0;
}
