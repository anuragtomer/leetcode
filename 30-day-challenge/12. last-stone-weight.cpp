#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int> &stones) {
        make_heap(stones.begin(), stones.end()); // This will rearrange stones to be a heap.
        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end()); // This will push first element to the back.
            int first = stones.back();
            stones.pop_back(); // This will remove element from the back.
            cout << "Popped " << first << endl;
            pop_heap(stones.begin(), stones.end());
            int second = stones.back();
            stones.pop_back();
            cout << "Popped " << second << endl;
            if (first - second > 0) {
                stones.push_back(first - second);
                push_heap(stones.begin(), stones.end());
                cout << "Pushing " << first - second << endl;
            }
            cout << "Size of stones is " << stones.size() << endl;
        }
        if (stones.empty())
            return 0;
        cout << stones[0] << endl;
        return stones[0];
    }
};

int main() {
    Solution sol;
    vector<int> stones{2, 7, 4, 1, 8, 1};
    assert(1 == sol.lastStoneWeight(stones));
    stones = {1, 3};
    assert(2 == sol.lastStoneWeight(stones));
    stones = {2, 2};
    assert(0 == sol.lastStoneWeight(stones));
    return 0;
}