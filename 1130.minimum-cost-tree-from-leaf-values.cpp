#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int mctFromLeafValues(vector<int> &arr) {
        int res = 0;
        vector<int> st;
        st.push_back(INT_MAX);
        for (int num : arr) {
            while (st.back() <= num) {
                int greater = st.back();
                st.pop_back();
                res += greater * (min(st.back(), num));
            }
            st.push_back(num);
        }
        for (int i = 2; i < st.size(); ++i) {
            res += st[i] * st[i - 1];
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}

