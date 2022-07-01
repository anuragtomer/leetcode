#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class FirstUnique {
    list<int> unique_queue;
    unordered_map<int, pair<bool, list<int>::iterator>> hash;

   public:
    FirstUnique(vector<int> &nums) {
        for (auto num : nums) {
            if (hash.find(num) == hash.end()) {
                unique_queue.push_front(num);
                hash[num] = {false, unique_queue.begin()};
            } else {
                if (hash[num].first == false) {
                    hash[num].first = true;
                    unique_queue.erase(hash[num].second);
                }
            }
        }
    }

    int showFirstUnique() {
        if (unique_queue.empty())
            return -1;
        return unique_queue.back();
    }

    void add(int num) {
        if (hash.find(num) == hash.end()) {
            unique_queue.push_front(num);
            hash[num] = {false, unique_queue.begin()};
        } else {
            if (hash[num].first == false) {
                hash[num].first = true;
                unique_queue.erase(hash[num].second);
            }
        }
    }
};

int main() {
    vector<int> nums{2, 3, 5};
    FirstUnique *obj = new FirstUnique(nums);
    assert(2 == obj->showFirstUnique());
    obj->add(5);
    assert(2 == obj->showFirstUnique());
    obj->add(2);
    assert(3 == obj->showFirstUnique());
    obj->add(3);
    assert(-1 == obj->showFirstUnique());
    return 0;
}
