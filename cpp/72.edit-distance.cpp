#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> pre = vector<int>(n + 1, 0);
        vector<int> cur;
        for (int i = 0; i <= n; ++i)
            pre[i] = i;
        int i = 0, j = 0;
        for (auto w2 : word2) {
            ++i;
            cur.push_back(i);
            j = 0;
            for (auto w1 : word1) {
                ++j;
                if (w1 == w2)
                    cur.push_back(pre[j - 1]);
                else
                    cur.push_back(1 + min(pre[j], min(pre[j - 1], cur.back())));
            }
            pre.swap(cur);
            cur = vector<int>();
        }
        return pre.back();
    }
};

int main() {
    Solution sol;
    string word1, word2;
    word1 = "horse", word2 = "ros";
    assert(3 == sol.minDistance(word1, word2));
    word1 = "intention", word2 = "execution";
    assert(5 == sol.minDistance(word1, word2));
    return 0;
}

