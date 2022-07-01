/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  int getImportance(vector<Employee*> employees, int _id) {
    queue<int> q;
    int importance = 0;
    q.push(_id);
    unordered_map<int, Employee*> hash;
    for (auto emp: employees) {
      hash[emp->id] = emp;
    }
    while (not q.empty()) {
      int id = q.front();
      q.pop();
      importance += hash[id]->importance;
      for (const int &subord: hash[id]->subordinates)
        q.push(subord);
    }
    return importance;
  }
};
