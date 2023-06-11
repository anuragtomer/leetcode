#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T>
class LRUCache {
  unordered_map<int, typename list<pair<int, T>>::iterator> hash;
  unsigned int hashCapacity;
  list<pair<int, T>> cache;

  void touch(int &key) {
    auto kv = *hash[key];
    cache.erase(hash[key]);
    cache.push_front(kv);
    hash[kv.first] = cache.begin();
  }

  void cleanupOldest() {
    auto del_item = prev(cache.end());
    hash.erase(cache.back().first);
    cache.erase(del_item);
  }

 public:
  LRUCache(int capacity) { hashCapacity = capacity; }

  bool get(int key, T *val) {
    if (hash.find(key) != hash.end()) {
      *val = hash[key]->second;
      touch(key);
      return true;
    }
    return false;
  }

  void put(int key, T value) {
    if (hash.find(key) != hash.end()) {
      cache.erase(hash[key]);
      hash.erase(key);
    }
    cache.push_front({key, value});
    hash[key] = cache.begin();
    if (cache.size() > hashCapacity)
      cleanupOldest();
  }
};
int main() {
  {
    int capacity = 2;
    LRUCache cache = LRUCache<int>(capacity);
    cache.put(1, 1);
    cache.put(2, 2);
    int ret;
    assert(cache.get(1, &ret)); // returns 1
    assert(ret == 1);
    cache.put(3, 3);                // evicts key 2
    assert(not cache.get(2, &ret)); // returns -1 (not found)
    cache.put(4, 4);                // evicts key 1
    assert(not cache.get(1, &ret)); // returns -1 (not found)
    assert(cache.get(3, &ret));     // returns 3
    assert(ret == 3);
    assert(cache.get(4, &ret)); // returns 4
    assert(ret == 4);
  }
  {
    int capacity = 3;
    LRUCache cache = LRUCache<string>(capacity);
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    cache.put(4, "four");
    string output;
    assert(cache.get(4, &output));
    assert(output == "four");
    output.clear();
    assert(cache.get(3, &output));
    assert(output == "three");
    output.clear();
    assert(cache.get(2, &output));
    assert("two" == output);
    output.clear();
    assert(not cache.get(1, &output));
    cache.put(5, "five");
    output.clear();
    assert(not cache.get(1, &output));
    output.clear();
    assert(cache.get(2, &output));
    assert("two" == output);
    output.clear();
    assert(cache.get(3, &output));
    assert(output == "three");
    assert(not cache.get(4, &output));
    output.clear();
    assert(cache.get(5, &output));
    assert(output == "five");
  }
  cout << "All the test cases passed.";
  return 0;
}
