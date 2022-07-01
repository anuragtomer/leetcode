#include <iostream>
#include <list>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> nums;
    default_random_engine generator;

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
            int last = nums.back(); // Value at the end of vector.
            hash[last] =
                hash[val]; // Put new index for last element as the index of the element we are going to remove.
            nums[hash[val]] = last; // Put last element at position of the element being removed.
            nums.pop_back();        // Either remove the last element, or reduce the size of array by 1.
            hash.erase(val);        // Remove val from hash also.
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> distribution(0, nums.size() - 1);
        return nums[distribution(generator)];
    }
};

int main() {
    RandomizedSet RS;
    assert(true == RS.insert(5));
    assert(false == RS.remove(6));
    assert(5 == RS.getRandom());
    return 0;
}
