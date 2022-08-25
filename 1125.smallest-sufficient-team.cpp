#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &people) {
    int n = req_skills.size();
    unordered_map<int, vector<int>> res;
    // Using reserved space, we avoid rehash, i.e. we avoid iterator
    // invalidation in last for loop where we are iterating and adding
    // elements to map.
    res.reserve(1 << n);
    res[0] = {};
    unordered_map<string, int> skill_map;
    for (int i = 0; i < n; i++)
      skill_map[req_skills[i]] = i;

    for (int i = 0, m = people.size(); i < m; i++) {
      int curr_skill = 0;
      for (int j = 0; j < people[i].size(); j++)
        curr_skill |= 1 << skill_map[people[i][j]];

      for (auto it = res.begin(); it != res.end(); it++) {
        int comb = it->first | curr_skill;
        if (res.find(comb) == res.end() ||
            res[comb].size() > 1 + res[it->first].size()) {
          res[comb] = it->second;
          res[comb].push_back(i);
        }
      }
    }
    return res[(1 << n) - 1];
  }
};
int main() {
  auto lmatch_result = [](vector<int> &a, vector<int> &b) -> bool {
    if (a.size() != b.size())
      return false;
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i)
      if (a[i] != b[i])
        return false;
    std::cout << "Passed.\n";
    return true;
  };
  Solution sol;
  vector<string> req_skills = {"java", "nodejs", "reactjs"};
  vector<vector<string>> people = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  vector<int> expected = {0, 2};
  vector<int> output = sol.smallestSufficientTeam(req_skills, people);
  assert(lmatch_result(expected, output));
  req_skills = {"algorithms", "math", "java", "reactjs", "csharp", "aws"};
  people = {{"algorithms", "math", "java"},
            {"algorithms", "math", "reactjs"},
            {"java", "csharp", "aws"},
            {"reactjs", "csharp"},
            {"csharp", "math"},
            {"aws", "java"}};
  expected = {1, 2};
  output = sol.smallestSufficientTeam(req_skills, people);
  assert(lmatch_result(expected, output));
  req_skills = {"a", "b", "c", "d", "e"};
  people = {{},         {},         {},    {},    {"b"},
            {"b", "e"}, {"b", "c"}, {"a"}, {"d"}, {"a", "c"}};
  expected = {5, 8, 9};
  output = sol.smallestSufficientTeam(req_skills, people);
  assert(lmatch_result(expected, output));
  return 0;
}
/* Python2 code
def smallestSufficientTeam(self, req_skills, people):
    n, m = len(req_skills), len(people)
    key = {v: i for i, v in enumerate(req_skills)}
    dp = {0: []}
    for i, p in enumerate(people):
        his_skill = 0
        for skill in p:
            if skill in key:
                his_skill |= 1 << key[skill]
        for skill_set, need in dp.items():
            with_him = skill_set | his_skill
            if with_him == skill_set: continue
            if with_him not in dp or len(dp[with_him]) > len(need) + 1:
                dp[with_him] = need + [i]
    return dp[(1 << n) - 1]
*/
