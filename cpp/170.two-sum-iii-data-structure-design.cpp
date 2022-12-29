#include <iostream>
#include <set>

using namespace std;

class TwoSum {
  multiset<int> nums;

 public:
  TwoSum() {}
  void add(int num) { nums.insert(num); }
  bool find(int target) {
    for (auto left = nums.begin(), right = prev(nums.end()); left != right;) {
      if (*left + *right == target)
        return true;
      else if (*left + *right < target) {
        left = next(left);
      } else {
        right = prev(right);
      }
    }
    return false;
  }
};

int main() {
  TwoSum *ts = new TwoSum();
  ts->add(1);
  ts->add(3);
  ts->add(5);
  ts->add(5);
  assert(ts->find(4));
  assert(not ts->find(7));
  assert(ts->find(10));
  cout << "Pass";
  return 0;
}
