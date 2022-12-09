/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if (p[1] == '*')
            /* 
             * s matches zero occurances of p[0].
             * OR
             * s is not empty AND first character matches/first char of p is '.' AND further chars of s match p
             */
            return (isMatch(s, p.substr(2)) || // S matches zero occurance of p[0], skip 2 chars in p.
                      !s.empty() && 
                      (s[0] == p[0] || '.' == p[0]) && 
                      isMatch(s.substr(1), p));
        else
            /*
             * first char of s matches (p or '.') AND further chars of s and p match.
             */
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};

bool expected(bool a, bool b) {
    return a == b;
}

int main() {
    string s;
    string p;
    Solution sol;
    s = "aa";
    p = "a";
    if (!expected(false, sol.isMatch(s, p)))
        return 1;
    s = "aa";
    p = "a*";
    if (!expected(true, sol.isMatch(s, p)))
        return 1;
    s = "ab";
    p = ".*";
    if (!expected(true, sol.isMatch(s, p)))
        return 1;
    s = "aab";
    p = "c*a*b";
    if (!expected(true, sol.isMatch(s, p)))
        return 1;
    s = "mississippi";
    p = "mis*is*p*.";
    if (!expected(false, sol.isMatch(s, p)))
        return 1;
    s = "aaa";
    p = "ab*a*c*a";
    if (!expected(true, sol.isMatch(s, p)))
        return 1;    
    s = "aaaaaaaaaaaaab";
    p = "a*a*a*a*a*a*a*a*a*a*c";
    if (!expected(false, sol.isMatch(s, p)))
        return 1;
    cout << "PASSED..";
    return 0;
}
// @lc code=end

