#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> nums;

   public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        hash.clear();
        nums.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) == hash.end()) {
            nums.push_back(val);
            hash[val] = nums.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) != hash.end()) {
            int last = nums.back();
            hash[last] = hash[val];
            nums[hash[val]] = last;
            nums.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % nums.size();
        return nums[random];
    }
};

int main() {
    RandomizedSet RS;
    assert(true == RS.insert(5));
    assert(false == RS.remove(6));
    assert(5 == RS.getRandom());
    return 0;
}
