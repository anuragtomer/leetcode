#include <iostream>
using namespace std;

class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int j = 0;
        for (auto i = 0; i < S.size(); i++) {
            if (S[i] == '#') {
                j--;
                if (j < 0)
                    j = 0;
            } else {
                S[j] = S[i];
                j++;
            }
        }
        S.resize(j);
        j = 0;
        for (auto i = 0; i < T.size(); i++) {
            if (T[i] == '#') {
                j--;
                if (j < 0)
                    j = 0;
            } else {
                T[j] = T[i];
                j++;
            }
        }
        T.resize(j);
        return S == T;
    }
};

int main() {
    Solution sol;
    string S{"a#b#c#######abc#"};
    string T{"abc###abc#"};
    cout << boolalpha << sol.backspaceCompare(S, T);
    return 0;
}