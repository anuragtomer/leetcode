#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string s) {
        vector<int> prev = {-1, -1, -1};
        int answer = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            prev[s[i] - 'a'] = i;
            answer += 1 + min({prev[0], prev[1], prev[2]});
        }
        return answer;
    }
};

int main() {
    Solution sol;
    assert(10 == sol.numberOfSubstrings("abcabc"));
    assert(3 == sol.numberOfSubstrings("aaacb"));
    assert(1 == sol.numberOfSubstrings("abc"));
    return 0;
}
