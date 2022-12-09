#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class FindNumWithMostFactorsConcurrently {
 private:
  static FindNumWithMostFactorsConcurrently *instance;
  std::thread::id mainThreadName;
  int callCount;
  FindNumWithMostFactorsConcurrently() {
    mainThreadName = std::this_thread::get_id();
    callCount = 0;
  }

 public:
  virtual ~FindNumWithMostFactorsConcurrently() {}
  static FindNumWithMostFactorsConcurrently *getInstance() {
    if (instance == NULL) {
      instance = new FindNumWithMostFactorsConcurrently();
    }
    return instance;
  }

  static void killInstance() {
    if (instance != NULL) {
      delete instance;
      instance = NULL;
    }
  }

  int getCallCount() { return callCount; }

  std::vector<int> searchRange(int start, int end) {
    std::vector<int> factors;
    if (mainThreadName == std::this_thread::get_id()) {
      return factors;
    }
    callCount++;
    factors.push_back(0);
    factors.push_back(0);
    for (int i = start; i <= end; i++) {
      int factorsCount = 0;
      for (int j = 1; j <= i; j++) {
        if (i % j == 0)
          factorsCount++;
      }
      if (factorsCount > factors[0] || factorsCount == factors[0] && i > factors[1]) {
        factors[0] = factorsCount;
        factors[1] = i;
      }
    }
    return factors;
  }
};
FindNumWithMostFactorsConcurrently *FindNumWithMostFactorsConcurrently::instance = NULL;
class Solution {
 public:
  int findNumWithMostFactors(int n, int m) {
    int offset = m / n;
    FindNumWithMostFactorsConcurrently *parallelWorker = FindNumWithMostFactorsConcurrently::getInstance();
    vector<future<vector<int>>> threads;
    for (int i = 0; i < m;) {
      int start = i, end = min(m, i + offset);
      threads.push_back(async(&FindNumWithMostFactorsConcurrently::searchRange, parallelWorker, start, end));
      i = i + offset;
      if (i > m)
        break;
    }
    int maxFactors = INT_MIN, number = INT_MAX;
    for (auto &t : threads) {
      vector<int> result = t.get();
      if (result[0] >= maxFactors) {
        if (result[0] == maxFactors) {
          number = max(number, result[1]);
        } else {
          number = result[1];
        }
        maxFactors = max(maxFactors, result[0]);
      }
    }
    return number;
  }
};

int main() {
  FindNumWithMostFactorsConcurrently *instance = FindNumWithMostFactorsConcurrently::getInstance();
  Solution solution;
  int n = 1, m = 3;
  int answer = solution.findNumWithMostFactors(n, m);
  cout << "Result: " << answer << " Expected: 3" << endl;
  cout << "Result: " << solution.findNumWithMostFactors(2, 5) << " Expected: 4" << endl;
  return 0;
}

