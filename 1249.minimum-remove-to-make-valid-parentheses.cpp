#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        vector<int> st;
        int openCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto &ch = s[i];
            switch (ch) {
                case '(':
                    openCount++;
                    st.push_back(i);
                    break;
                case ')':
                    if (openCount > 0) {
                        st.pop_back();
                        openCount--;
                    } else
                        ch = '*';
                    break;
            }
        }
        for (auto i : st) {
            s[i] = '*';
        }
        string res;
        res.reserve(s.size());
        for (auto ch : s) {
            if (ch != '*')
                res.push_back(ch);
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}

