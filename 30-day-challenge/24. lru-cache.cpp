#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;
class LRUCache {
    int cacheSize;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> lst;
    void rearrange_cache(list<pair<int, int>>::iterator it) {
        pair<int, int> val = *it;
        lst.erase(it);
        lst.push_front(val);
    }

   public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {
            rearrange_cache(hash[key]);
            hash[key] = lst.begin();
            return hash[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.find(key) == hash.end()) {
            if (lst.size() == cacheSize) {
                hash.erase(lst.back().first);
                lst.pop_back();
            }
            lst.push_front(make_pair(key, value));
            hash[key] = lst.begin();
        } else {
            hash[key]->second = value;
            rearrange_cache(hash[key]);
            hash[key] = lst.begin();
        }
    }
};

int main() {
    int capacity = 2;
    LRUCache *obj2 = new LRUCache(capacity);
    obj2->put(1, 1);
    obj2->put(2, 2);
    assert(1 == obj2->get(1));
    obj2->put(3, 3);
    assert(-1 == obj2->get(2));
    obj2->put(4, 4);
    assert(-1 == obj2->get(1));
    assert(3 == obj2->get(3));
    assert(4 == obj2->get(4));
    LRUCache *obj = new LRUCache(1);
    obj->put(2, 1);
    assert(1 == obj->get(2));
    obj->put(3, 2);
    assert(obj->get(2) == -1);
    assert(obj->get(3) == 2);
    return 0;
}
