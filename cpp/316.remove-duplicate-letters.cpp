#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256, 0);
        for (auto ch : s)
            count[ch]++;
        string st;
        unordered_set<char> u_set;
        for (auto ch : s) {
            while (!st.empty() && st.back() >= ch && count[st.back()] > 0 && u_set.count(ch) == 0) {
                u_set.erase(u_set.find(st.back()));
                st.pop_back();
            }
            if (u_set.count(ch) == 0) {
                st.push_back(ch);
                u_set.insert(ch);
            }
            --count[ch];
        }
        return st;
    }
};

int main() {
    Solution sol;

    return 0;
}

