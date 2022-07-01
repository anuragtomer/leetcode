#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * @param s: the given string
     * @return: the number of A
     */
    int countA(string &s) {
        int i = 0;
        while (i < s.size() && s[i] != 'A')
            ++i;
        int count = 0;
        while (i < s.size() && s[i] == 'A') {
            ++count;
            ++i;
        }
        return count;
    }
};

int main() {
    Solution sol;

    return 0;
}

