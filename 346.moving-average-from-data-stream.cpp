#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class MovingAverage {
    int sz;
    list<int> nums;
    double sum;

   public:
    /*
     * @param size: An integer
     */
    MovingAverage(int size) {
        sz = size;
        sum = 0.0;
    }

    /*
     * @param val: An integer
     * @return:
     */
    double next(int val) {
        if (nums.size() < sz) {
            nums.push_back(val);
            sum += val;
            return sum / nums.size();
        } else {
            sum -= nums.front();
            nums.pop_front();
            nums.push_back(val);
            sum += val;
            return sum / sz;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
int main() {
    Solution sol;

    return 0;
}

