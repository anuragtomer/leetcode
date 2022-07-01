#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> hash;
        int count = 0;
        // Find out what is the highest frequency of any task.
        for (auto task : tasks) {
            hash[task]++;
            count = max(count, hash[task]);
        }
        int ans = (count - 1) * (n + 1); // Max time to finish most frequent task is this.
        for (auto it : hash) {
            if (it.second == count) // If there are more tasks with same highest frequency, they would go beyond our
                                    // first most frequent task.
                ans++;
        }
        return max(static_cast<int>(tasks.size()),
                   ans); // Finally, there might be a lot of smaller tasks. We can fit in those anywhere. Size cannot be
                         // smaller than the total tasks to be computed.
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'a', 'a', 'a', 'b', 'b', 'b'};
    assert(8 == sol.leastInterval(tasks, 2));
    assert(6 == sol.leastInterval(tasks, 0));
    return 0;
}

