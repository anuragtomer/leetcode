#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::list;
using std::string;
using std::unordered_map;
using std::unordered_set;

class AllOne {
 private:
  struct Bucket {
    int value;
    unordered_set<string> keys;
  };
  list<Bucket> buckets;
  // buckets are something like this
  // {0, {"xyz"}}, {0, {"abc", "def", "ghi"}}, {1, {"abcd", "defg"}}, {2,
  // {"abcde", "ghijk", "cdefgh"}}
  unordered_map<string, list<Bucket>::iterator> bucketOfKey;
  // each bucketOfKey maps a string to its rightful bucket
  // abc::1
  // def::1
  // ghi::1
  // abcd::2
  // defg::2
  // abcde::3
  // ghijk::3
  // cdefgh::3
  // xyz::0

 public:
  void inc(string key) {
    // If the key doesn't exist, insert it with value 0.
    if (!bucketOfKey.count(key))
      bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});

    // Insert the key in next bucket and update the lookup.
    auto bucket = bucketOfKey[key];
    auto next = bucket;
    next++;
    if (next == buckets.end() || next->value > bucket->value + 1)
      next = buckets.insert(next, {bucket->value + 1, {}});
    next->keys.insert(key);
    bucketOfKey[key] = next;

    // Remove the key from its old bucket.
    bucket->keys.erase(key);
    if (bucket->keys.empty()) {
      buckets.erase(bucket);
    }
  }

  void dec(string key) {
    // If the key doesn't exist, just leave.
    if (!bucketOfKey.count(key)) {
      return;
    }
    // Maybe insert the key in previous bucket and update the lookup.
    auto bucket = bucketOfKey[key];
    auto prev = bucket;
    --prev;
    bucketOfKey.erase(key);
    if (bucket->value > 1) {
      if (bucket == buckets.begin() || prev->value < bucket->value - 1)
        prev = buckets.insert(bucket, {bucket->value - 1, {}});
      prev->keys.insert(key);
      bucketOfKey[key] = prev;
    }

    // Remove the key from its old bucket.
    bucket->keys.erase(key);
    if (bucket->keys.empty()) {
      buckets.erase(bucket);
    }
  }

  string getMaxKey() {
    return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
  }

  string getMinKey() {
    return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
  }
};