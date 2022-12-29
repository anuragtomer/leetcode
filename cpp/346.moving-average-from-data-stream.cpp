#include <cassert>
#include <deque>
using namespace std;

class MovingAverage {
  deque<int> deq;
  double sum;
  int sz;

 public:
  MovingAverage(int size) : sz(size), sum(0.0) {}

  double next(int val) {
    deq.push_back(val);
    sum += val;
    if (deq.size() > sz) {
      sum -= deq.front();
      deq.pop_front();
    }
    return sum / deq.size();
  }
};

int main() {
  MovingAverage *mv = new MovingAverage(3);
  assert(mv->next(1) == 1.0);
  assert(mv->next(10) == ((1 + 10) / 2.0));
  assert(mv->next(3) == ((1 + 10 + 3) / 3.0));
  assert(mv->next(5) == ((10 + 3 + 5) / 3.0));
  return 0;
}
