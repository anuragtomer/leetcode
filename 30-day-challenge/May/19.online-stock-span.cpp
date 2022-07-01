#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;
    int day;

   public:
    StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        day = -1;
    }

    int next(int price) {
        day++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        if (st.empty()) {
            st.push({price, day});
            return day + 1;
        } else {
            int ret = day - st.top().second;
            st.push({price, day});
            return ret;
        }
    }
};

int main() {
    StockSpanner ss = StockSpanner();
    assert(ss.next(100) == 1);
    assert(ss.next(80) == 1);
    assert(ss.next(60) == 1);
    assert(ss.next(70) == 2);
    assert(ss.next(60) == 1);
    assert(ss.next(75) == 4);
    assert(ss.next(85) == 6);
    assert(ss.next(110) == 8);
    assert(ss.next(5) == 1);
    assert(ss.next(10) == 2);
    //
    StockSpanner s = StockSpanner();
    assert(s.next(28) == 1);
    assert(s.next(14) == 1);
    assert(s.next(28) == 3);
    assert(s.next(35) == 4);
    assert(s.next(46) == 5);
    assert(s.next(53) == 6);
    assert(s.next(66) == 7);
    assert(s.next(80) == 8);
    assert(s.next(87) == 9);
    assert(s.next(88) == 10);
    return 0;
}
