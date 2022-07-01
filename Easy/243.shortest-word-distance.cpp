#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param words: a list of words
     * @param word1: a string
     * @param word2: a string
     * @return: the shortest distance between word1 and word2 in the list
     */
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int i = -1, j = -1, minDistance = INT_MAX;
        for (int k = 0; k < words.size(); ++k) {
            if (words[k] == word1)
                i = k;
            else if (words[k] == word2)
                j = k;
            if (i != -1 && j != -1)
                minDistance = min(minDistance, abs(i - j));
        }
        if (i == -1 || j == -1)
            return -1;
        else
            return minDistance;
    }
};
int main() {
    Solution sol;

    return 0;
}

