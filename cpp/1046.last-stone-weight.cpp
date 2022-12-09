#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int> &stones) {
    make_heap(stones.begin(),
              stones.end()); // This will rearrange stones to be a heap.
    while (stones.size() > 1) {
      pop_heap(stones.begin(),
               stones.end()); // This will push first element to the back.
      int first = stones.back();
      stones.pop_back(); // This will remove element from the back.
      pop_heap(stones.begin(), stones.end());
      int second = stones.back();
      stones.pop_back();
      if (first - second > 0) {
        stones.push_back(first - second);
        push_heap(stones.begin(), stones.end());
      }
    }
    if (stones.empty())
      return 0;
    return stones[0];
  }
};
// Second solution using priority_queue (actual heap)
class Solution {
 public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> max_queue;
    for (auto &stone : stones) {
      max_queue.push(stone);
    }
    while (max_queue.size() > 1) {
      int stone1 = max_queue.top();
      max_queue.pop();
      int stone2 = max_queue.top();
      max_queue.pop();
      if (stone1 - stone2 > 0)
        max_queue.push(stone1 - stone2);
    }
    return max_queue.empty() ? 0 : max_queue.top();
  }
};

int main() {
  Solution sol;
  vector<int> stones{2, 7, 4, 1, 8, 1};
  assert(1 == sol.lastStoneWeight(stones));
  stones = {1, 3};
  assert(2 == sol.lastStoneWeight(stones));
  stones = {2, 2};
  assert(0 == sol.lastStoneWeight(stones));
  return 0;
}
