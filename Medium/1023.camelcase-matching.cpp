#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<bool> result;
        size_t psize = pattern.size();
        for (auto query : queries) {
            int p = 0, i = 0, qsize = query.size();
            bool equivalent = true;
            for (; i < qsize; ++i) {
                if (p < psize && query[i] == pattern[p]) {
                    p++;
                } else if (isupper(query[i])) {
                    break;
                }
            }
            result.push_back(p == psize && i == qsize);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    string pattern = "FB";
    vector<bool> output = sol.camelMatch(queries, pattern);
    vector<bool> result = {true, false, true, true, false};
    assert(result.size() == output.size());
    for (auto i = 0; i < output.size(); ++i) {
        assert(output[i] == result[i]);
    }
    return 0;
}

