#include <iostream>

using namespace std;

class Solution{
    public:
        int minAddToMakeValid(string S) {
            int add = 0, left = 0;
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == ')') {
                    if (left > 0) {
                        left--;
                    } else {
                        add++;
                    }
                } else if (S[i] == '(') {
                    left++;
                }
            }
            return add + left;
        }
};
int main() {
    Solution sol;
    string str;
    cin >> str;
    cout << sol.minAddToMakeValid(str);
    return 0;
}


