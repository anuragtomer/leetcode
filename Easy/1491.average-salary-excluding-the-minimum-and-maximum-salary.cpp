class Solution {
 public:
  double average(vector<int> &salary) {
    int min_salary = INT_MAX, max_salary = INT_MIN;
    double total_salary = 0;
    for (auto &sal : salary) {
      total_salary += sal;
      if (min_salary > sal)
        min_salary = sal;
      if (max_salary = sal)
        max_salary = sal;
    }
    return (total_salary - (min_salary + max_salary)) / (salary.size() - 2);
  }
};
