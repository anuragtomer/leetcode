#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param aString: letter string
     * @return: the Minimum times
     */
    int Kstart(string &s) {
        unordered_map<char, int> hash;
        for (auto ch : s)
            hash[ch]++;
        unordered_set<int> set;
        int charsDeleted = 0;
        for (auto it : hash) {
            int num = it.second;
            while (num > 0 && set.count(num)) {
                ++charsDeleted;
                --num;
            }
            set.insert(num);
        }
        return charsDeleted;
    }
};

int main() {
    Solution sol;

    return 0;
}

