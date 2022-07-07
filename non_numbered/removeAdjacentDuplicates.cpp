#include "lib.h"

class Solution {
public:
    string removeDuplicates(string S) {
        for (int i = 0; i < S.size();) {
            if (i + 1 < S.size()) {
                if (S[i] == S[i + 1]) {
                    S.erase(i, 2);
                    if (i != 0) {
                        i--;
                    }
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        return S;
    }
};

int main(){
    Solution sol;
    string str;
    cin >> str;
    cout << sol.removeDuplicates(str) << endl;
    return 0;
}

/* Input: abbaca
 *  Output: ca
 *
 *  Input : abbabcaacb
 *  Output: ""
 */
