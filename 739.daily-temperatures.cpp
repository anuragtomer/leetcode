#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> result(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); ++i) {
            while (!st.empty() && T[st.top()] < T[i]) {
                auto top = st.top();
                st.pop();
                result[top] = i - top;
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    vector<int> result = sol.dailyTemperatures(T);
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i)
        assert(result[i] == expected[i]);
    return 0;
}

