#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;

   public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i)
            pq.push(i);
    }

    int reserve() {
        int top = pq.top();
        pq.pop();
        return top;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};

int main() {
    int n = 5;
    SeatManager *obj = new SeatManager(n);
    assert(1 == obj->reserve());
    assert(2 == obj->reserve());
    obj->unreserve(2);
    assert(2 == obj->reserve());
    assert(3 == obj->reserve());
    assert(4 == obj->reserve());
    assert(5 == obj->reserve());
    obj->unreserve(5);
    return 0;
}
