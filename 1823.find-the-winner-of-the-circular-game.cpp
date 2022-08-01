class Solution {
 public:
  int findTheWinner(int n, int k) {
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
      dq.push_back(i);
    int current = 0, next = 0;
    while (dq.size() > 1) {
      next = (current + k - 1) % dq.size();
      dq.erase(dq.begin() + next);
      current = next % dq.size();
    }
    return dq.front();
  }
};
