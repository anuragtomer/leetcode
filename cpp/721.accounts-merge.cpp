#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  string find(string email, unordered_map<string, string> &parent) {
    while (parent[email] != email) {
      email = parent[email];
    }
    return email;
  }

 public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    unordered_map<string, string> parents;
    unordered_map<string, string> ownerName;
    unordered_map<string, set<string>> mergedEmails;
    for (auto &account : accounts) {
      for (int i = 1; i < account.size(); ++i) {
        parents[account[i]] = account[i];
        ownerName[account[i]] = account[0];
      }
    }
    for (auto &account : accounts) {
      string p = find(account[1], parents);
      for (int i = 2; i < account.size(); ++i) {
        parents[find(account[i], parents)] = p;
      }
    }
    for (auto &account : accounts) {
      for (int i = 1; i < account.size(); ++i) {
        mergedEmails[find(account[i], parents)].insert(account[i]);
      }
    }
    vector<vector<string>> result;
    for (auto &email : mergedEmails) {
      vector<string> emails(email.second.begin(), email.second.end());
      emails.insert(emails.begin(), ownerName[*(email.second.begin())]);
      result.push_back(emails);
    }
    return result;
  }
};
int main() {
  auto lMatch = [](vector<vector<string>> out,
                   vector<vector<string>> &exp) -> bool {
    if (out.size() != exp.size())
      return false;
    sort(out.begin(), out.end());
    sort(exp.begin(), exp.end());
    for (int i = 0; i < out.size(); ++i) {
      if (out[i].size() != exp[i].size())
        return false;
      if (out[i][0] != exp[i][0])
        return false;
      sort(out[i].begin() + 1, out[i].end());
      sort(exp[i].begin() + 1, exp[i].end());
      for (int j = 1; j < out[i].size(); ++j)
        if (out[i][j] != exp[i][j])
          return false;
    }
    return true;
  };
  Solution sol;
  vector<vector<string>> accounts;
  vector<vector<string>> expected;
  accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
              {"John", "johnsmith@mail.com", "john00@mail.com"},
              {"Mary", "mary@mail.com"},
              {"John", "johnnybravo@mail.com"}};
  expected = {
    {"John", "johnnybravo@mail.com"},
    {"Mary", "mary@mail.com"},
    {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"}};
  assert(lMatch(sol.accountsMerge(accounts), expected));

  accounts = {{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
              {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
              {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
              {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
              {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
  expected = {{"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"},
              {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
              {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
              {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
              {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"}};

  assert(lMatch(sol.accountsMerge(accounts), expected));
  return 0;
}
