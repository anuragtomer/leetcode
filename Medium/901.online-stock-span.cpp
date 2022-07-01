#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
    int day;
    stack<pair<int, int>> st;

   public:
    StockSpanner() { day = -1; }

    int next(int price) {
        ++day;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        if (st.empty()) {
            st.push({price, day});
            return day + 1;
        }
        int retVal = day - st.top().second;
        st.push({price, day});
        return retVal;
    }
};

int main() { return 0; }

