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
  Solution sol;

  return 0;
}

