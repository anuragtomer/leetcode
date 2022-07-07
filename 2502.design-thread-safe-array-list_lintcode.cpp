#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_set>
#include <vector>
using namespace std;
class AbstractArrayList {
 private:
  int *elementData;
  int size;
  int capacity;

  int *copyArray(int original, const int newCapacity) {
    int *copy = new int[newCapacity];
    for (int i = 0; i < original; ++i)
      copy[i] = elementData[i];
    delete[] elementData;
    return copy;
  }
  void ensureCapacityInternal(int minCapacity) {
    if (minCapacity > capacity) {
      capacity *= 2;
      elementData = copyArray(size, capacity);
    }
  }

 public:
  AbstractArrayList() {
    capacity = 10;
    elementData = new int[capacity];
    size = 0;
  }
  ~AbstractArrayList() { delete[] elementData; }
  int get(int index) {
    if (index >= size)
      return -1;
    return elementData[index];
  }
  void append(int element) {
    ensureCapacityInternal(size + 1);
    this_thread::sleep_for(chrono::microseconds(1000));
    elementData[size] = element;
    this_thread::sleep_for(chrono::microseconds(1000));
    size++;
  }
  int getSize() { return size; }
};
class ThreadSafeArrayList : public AbstractArrayList {
  mutex m;

 public:
  ThreadSafeArrayList() : AbstractArrayList() {}
  virtual ~ThreadSafeArrayList() {}
  void append(int element) {
    m.lock();
    AbstractArrayList::append(element);
    m.unlock();
  }
  int get(int index) { return AbstractArrayList::get(index); }
};
int main() {
  vector<thread *> threads;
  ThreadSafeArrayList TSAL;
  unordered_set<int> nums;
  const int N = 100;
  for (int i = 0; i < N; ++i) {
    threads.push_back(new thread(&ThreadSafeArrayList::append, ref(TSAL), i + 1));
    nums.insert(i + 1);
  }
  for (auto &t : threads)
    if (t->joinable())
      t->join();
  for (int i = 0; i < N; ++i) {
    int elem = TSAL.get(i);
    cout << elem << " ";
    if (nums.find(elem) == nums.end())
      cout << "Some elements missing \n";
    else
      nums.erase(elem);
  }
  return 0;
}
