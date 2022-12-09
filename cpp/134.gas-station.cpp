#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> values;
        int n = gas.size();

        for (int i = 0; i < n; ++i)
            values.push_back(gas[i] - cost[i]);
        int starting = 0, total_fuel = 0;
        if (n == 1) {
            if (values[0] >= 0)
                return 0;
            else
                return -1;
        }
        for (auto c : values) {
            total_fuel += c;
        }
        if (total_fuel < 0)
            return -1;
        while (true) {
            for (; starting < n; ++starting) {
                if (values[starting] > 0)
                    break;
            }
            if (starting == n)
                return -1;
            bool flag = false;
            int fuel_left = 0;
            for (int i = starting; true; i = (i + 1) % n) {
                if (i == starting && flag == false)
                    flag = true;
                else if (i == starting && flag == true)
                    return starting;
                fuel_left += values[i];
                if (fuel_left <= 0) {
                    if (fuel_left == 0 && i == (starting - 1 + n) % n)
                        return starting;
                    else
                        break;
                }
            }
            starting++;
        }
        return -1;
    }
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size() - 1, start = n, end = 0, fuel = 0;
        fuel = gas[n] - cost[n];
        while (end < start) {
            if (fuel >= 0) {
                fuel += gas[end] - cost[end];
                end++;
            } else {
                start--;
                fuel += gas[start] - cost[start];
            }
        }
        return (fuel >= 0) ? start : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};
    assert(3 == sol.canCompleteCircuit(gas, cost));
    gas = {2, 3, 4}, cost = {3, 4, 3};
    assert(-1 == sol.canCompleteCircuit(gas, cost));
    gas = {4, 5, 3, 1, 4}, cost = {5, 4, 3, 4, 2};
    assert(-1 == sol.canCompleteCircuit(gas, cost));
    gas = {2}, cost = {2};
    assert(0 == sol.canCompleteCircuit(gas, cost));
    return 0;
}
