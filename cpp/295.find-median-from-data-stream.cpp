#include <cassert>
#include <queue>
using namespace std;

class MedianFinder {
  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int, vector<int>, less<int>> max_heap;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (min_heap.empty() || min_heap.top() < num)
      min_heap.push(num);
    else
      max_heap.push(num);
    if (static_cast<int>(min_heap.size()) - static_cast<int>(max_heap.size()) >=
        2) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    } else if (static_cast<int>(max_heap.size()) -
                 static_cast<int>(min_heap.size()) >=
               2) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }

  double findMedian() {
    if (min_heap.size() < max_heap.size()) {
      return static_cast<double>(max_heap.top());
    } else if (min_heap.size() > max_heap.size())
      return static_cast<double>(min_heap.top());
    else if (not min_heap.empty() && not max_heap.empty())
      return (static_cast<double>(min_heap.top()) +
              static_cast<double>(max_heap.top())) /
             2.0;
    else
      return 0.0;
  }
};
int main() {
  MedianFinder medianFinder;                // = new MedianFinder();
  medianFinder.addNum(1);                   // arr = [1]
  medianFinder.addNum(2);                   // arr = [1, 2]
  assert(1.5 == medianFinder.findMedian()); // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder.addNum(3);                   // arr[1, 2, 3]
  assert(2.0 == medianFinder.findMedian()); // return 2.0
  return 0;
}
