#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  /*    vector<int> findClosestElements(vector<int> &A, int k, int x) {
        auto comp = [&](int &a, int &b) {
            if (abs(a - x) == abs(b - x))
                return a > b;
            return abs(a - x) > abs(b - x);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto num : A) {
            pq.push(num);
        }
        vector<int> result;
        while (k) {
            --k;
            result.push_back(pq.top());
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }*/
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    if (k >= arr.size())
      return arr;
    int left = 0, right = arr.size() - 1;
    while (right - left + 1 > k) {
      if (abs(arr[left] - x) > abs(arr[right] - x))
        ++left;
      else
        --right;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
  }
};

int main() {
  Solution sol;

  return 0;
}

