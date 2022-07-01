#include <iostream>
using namespace std;

class Solution {
    bool checkPalindrome(string palindrome) {
        int sz = palindrome.size();         // 3
        for (int i = 0; i <= sz / 2; i++) { // 0 to 1
            if (palindrome[i] != palindrome[sz - i - 1])
                return false;
        }
        return true;
    }

   public:
    // Another solution. Smaller no of lines.
    string breakPalindrome(string S) {
        int n = S.size();
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return n < 2 ? "" : S;
    }
    /*
    string breakPalindrome(string palindrome) {
        bool changed = false;
        char orig;
        for (auto &ch : palindrome) {
            if (ch != 'a') {
                orig = ch;
                ch = 'a';
                if (!checkPalindrome(palindrome)) {
                    cout << palindrome << endl;
                    return palindrome;
                }
                ch = orig;
            }
        }
        for (auto ch = palindrome.rbegin(); ch != palindrome.rend(); ++ch) {
            if (*ch != 'z') {
                orig = *ch;
                *ch = *ch + 1;
                if (!checkPalindrome(palindrome)) {
                    cout << palindrome << endl;
                    return palindrome;
                }
                *ch = orig;
            }
        }
        cout << "" << endl;
        return "";
    }
*/
};
int main() {
    Solution sol;
    string palindrome = "abccba";
    assert(sol.breakPalindrome(palindrome) == "aaccba");
    palindrome = "a";
    assert(sol.breakPalindrome(palindrome) == "");
    palindrome = "aa";
    assert(sol.breakPalindrome(palindrome) == "ab");
    palindrome = "aba";
    assert(sol.breakPalindrome(palindrome) == "abb");
    return 0;
}