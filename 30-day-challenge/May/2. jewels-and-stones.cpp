#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        int count = 0;
        for (auto ch : J)
            jewels.insert(ch);
        for (auto ch : S) {
            if (jewels.find(ch) != jewels.end())
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    assert(3 == sol.numJewelsInStones("aA", "aAAbbbb"));
    assert(0 == sol.numJewelsInStones("z", "ZZ"));
    return 0;
}
