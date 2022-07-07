#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedCollection {
    unordered_map<int, vector<int>> hash;
    vector<pair<int, int>> nums;
    default_random_engine engine;

   public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool result = hash.find(val) == hash.end();
        nums.push_back({val, hash[val].size()});
        hash[val].push_back(nums.size() - 1);
        return result;
    }

    bool remove(int val) {
        if (hash.find(val) == hash.end())
            return false;
        auto last = nums.back();
        hash[last.first][last.second] = hash[val].back();
        nums[hash[val].back()] = last;
        nums.pop_back();
        hash[val].pop_back();
        if (hash[val].size() == 0)
            hash.erase(val);
        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> distribution(0, nums.size() - 1);
        return nums[distribution(engine)].first;
    }
};
/*
 * 1,0; 2,0;
 * [1] = 0
 * [2] = 1
 **/
int main() {
    RandomizedCollection *obj = new RandomizedCollection();
    assert(obj->insert(1));
    assert(!obj->insert(1));
    assert(obj->insert(2));
    cout << obj->getRandom() << " ";
    assert(obj->remove(1));
    cout << obj->getRandom() << " ";

    return 0;
}

