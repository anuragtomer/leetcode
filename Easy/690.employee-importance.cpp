#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Employee {
   public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
   public:
    int getImportance(vector<Employee *> employees, int id) {
        int sum = 0;
        unordered_map<int, Employee *> mappings;
        for (auto employee : employees)
            mappings[employee->id] = employee;
        dfs(mappings, id, sum);
        return sum;
    }
    void dfs(unordered_map<int, Employee *> &mappings, int id, int &sum) {
        sum += mappings[id]->importance;
        for (auto sub : mappings[id]->subordinates)
            dfs(mappings, sub, sum);
    }
};

int main() {
    Solution sol;

    return 0;
}

