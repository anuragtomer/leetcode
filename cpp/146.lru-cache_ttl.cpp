#include <cassert>
#include <chrono>
#include <iostream>
#include <list>
#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T>
struct Object {
  T val;
  std::chrono::time_point<std::chrono::system_clock> access_time;
  Object(T val_, chrono::time_point<chrono::system_clock> access_time_)
    : val{val_}, access_time{access_time_} {}
};

template <class T>
class LRUCache {
  unordered_map<int, typename list<pair<int, shared_ptr<Object<T>>>>::iterator>
    hash;
  unsigned int hashCapacity;
  list<pair<int, shared_ptr<Object<T>>>> cache;
  chrono::milliseconds ttl;

  void bump(int &key,
            std::chrono::time_point<std::chrono::system_clock> last_accessed) {
    auto kv = *hash[key];
    kv.second->access_time = last_accessed;
    cache.erase(hash[key]);
    cache.push_front(kv);
    hash[kv.first] = cache.begin();
  }

  void cleanupExpired(int &key) {
    auto kv = hash[key];
    hash.erase(key);
    cache.erase(kv);
  }

  void cleanupOldest() {
    auto del_item = prev(cache.end());
    hash.erase(cache.back().first);
    cache.erase(del_item);
  }

 public:
  LRUCache(unsigned int capacity, chrono::milliseconds ttl_)
    : hashCapacity{capacity}, ttl{ttl_} {}

  bool get(int key, T &val) {
    if (hash.find(key) == hash.end()) {
      return false;
    } else if (std::chrono::system_clock::now() -
                 hash[key]->second->access_time >=
               ttl) {
      cleanupExpired(key);
      return false;
    } else {
      val = hash[key]->second->val;
      bump(key, std::chrono::system_clock::now());
      return true;
    }
  }

  void put(int key, T val) {
    if (hash.find(key) != hash.end()) {
      cache.erase(hash[key]);
      hash.erase(key);
    }
    cache.push_front(
      {key, make_shared<Object<T>>(val, chrono::system_clock::now())});
    hash[key] = cache.begin();
    if (cache.size() > hashCapacity) {
      // Cache Overflow
      cleanupOldest();
    }
  }
};
int main() {
  {
    int capacity = 2;
    int ret;
    LRUCache cache = LRUCache<int>(capacity, 120ms);
    cache.put(1, 1);
    this_thread::sleep_for(chrono::milliseconds(60));
    cache.put(2, 2);
    this_thread::sleep_for(chrono::milliseconds(50));
    assert(cache.get(1, ret)); // returns 1
    assert(ret == 1);
    this_thread::sleep_for(chrono::milliseconds(60));
    cache.put(3, 3); // evicts key 2
    this_thread::sleep_for(chrono::milliseconds(60));
    assert(not cache.get(2, ret)); // returns -1 (not found)
    cache.put(4, 4);               // evicts key 1
    assert(not cache.get(1, ret)); // returns -1 (not found)
    assert(cache.get(3, ret));     // returns 3
    assert(ret == 3);
    this_thread::sleep_for(chrono::milliseconds(120));
    assert(not cache.get(3, ret)); // returns -1 because of timeout.
    assert(not cache.get(4, ret)); // returns -1 because of timeout.
  }
  cout << "All the test cases passed.";
  return 0;
}
