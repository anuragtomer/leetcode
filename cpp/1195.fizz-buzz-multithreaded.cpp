#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class FizzBuzz {
 private:
  int n;
  condition_variable cv;
  mutex m;
  int current;

 public:
  FizzBuzz(int n) {
    this->n = n;
    current = 1;
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while (current <= n) {
      unique_lock<mutex> l(m);
      //cout << "Waiting for multiple of 3\n";
      cv.wait(l, [=]() { return (current % 3 == 0 && current % 5 != 0) || (current > n); });
      //cout << "Done waiting for multiple of 3\n";
      if (current <= n)
        printFizz();
      ++current;
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    while (current <= n) {
      unique_lock<mutex> l(m);
      //cout << "Waiting for multiple of 5\n";
      cv.wait(l, [=]() { return (current % 3 != 0 && current % 5 == 0) || (current > n); });
      //cout << "Done for multiple of 5\n";
      if (current <= n)
        printBuzz();
      ++current;
      cv.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (current <= n) {
      unique_lock<mutex> l(m);
      //cout << "Waiting for multiple of both 3 and 5\n";
      cv.wait(l, [=]() { return (current % 3 == 0 && current % 5 == 0) || (current > n); });
      //cout << "Done waiting for multiple of both\n";
      if (current <= n)
        printFizzBuzz();
      ++current;
      cv.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    while (current <= n) {
      unique_lock<mutex> l(m);
      //cout << "waiting for number \n";
      cv.wait(l, [=]() { return (current % 3 != 0 && current % 5 != 0) || (current > n); });
      //cout << "Done waiting for number \n";
      if (current <= n)
        printNumber(current);
      ++current;
      cv.notify_all();
    }
  }
};
static void printFizz() {
  cout << "fizz ";
  cout << endl;
}
static void printBuzz() {
  cout << "buzz ";
  cout << endl;
}
static void printFizzBuzz() {
  cout << "fizzbuzz ";
  cout << endl;
}
static void printNumber(int num) {
  cout << num << " ";
  cout << endl;
}

int main() {
  FizzBuzz fb(15);
  vector<thread> threads;
  threads.push_back(thread(&FizzBuzz::buzz, ref(fb), printBuzz));
  threads.push_back(thread(&FizzBuzz::fizz, ref(fb), printFizz));
  threads.push_back(thread(&FizzBuzz::fizzbuzz, ref(fb), printFizzBuzz));
  threads.push_back(thread(&FizzBuzz::number, ref(fb), printNumber));
  for (auto &t : threads) {
    if (t.joinable())
      t.join();
  }
  return 0;
}

