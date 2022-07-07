#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
  vector<uint32_t> hash;

 public:
  /** Initialize your data structure here. */
  MyHashSet() { hash = vector<uint32_t>(1000000, -1); }

  void add(int key) { hash[key] = 1; }

  void remove(int key) { hash[key] = -1; }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return (hash[key] == 1); }
};

/**
 * Your MyHashSet object will be instantiated and called as such:*/
int main() {
  MyHashSet hashSet = MyHashSet();
  hashSet.add(1);
  hashSet.add(2);
  assert(true == hashSet.contains(1));   // returns true
  assert(false == hashSet.contains(3));  // returns false (not found)
  hashSet.add(2);
  assert(true == hashSet.contains(2));  // returns true
  hashSet.remove(2);
  assert(false == hashSet.contains(2));  // returns false (already removed)
  return 0;
}