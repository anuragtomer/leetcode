#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  void helper(vector<pair<char, int>> &countHash, vector<string> &result, string &s, int idx, string &oddChar, int n) {
    if (s.size() == n / 2) {
      string rev = s;
      if (!oddChar.empty())
        rev.append(oddChar);
      reverse(s.begin(), s.end());
      result.push_back(rev + s);
      return;
    }
    for (int i = 0; i < countHash.size(); ++i) {
      if (countHash[i].second >= 2) {
        s.push_back(countHash[i].first);
        countHash[i].second -= 2;
        helper(countHash, result, s, i, oddChar, n);
        countHash[i].second += 2;
        s.pop_back();
      }
    }
  }

 public:
  vector<string> generatePalindromes(string s) {
    vector<string> result;
    unordered_map<char, int> countHash;
    for (auto &ch : s) {
      countHash[ch]++;
    }
    vector<pair<char, int>> counts;
    bool oddFound = false;
    string oddChar = "";
    int n = 0;
    for (auto hash : countHash) {
      if (hash.second % 2 == 1) {
        if (oddFound)
          return result;
        else {
          oddFound = true;
          oddChar.push_back(hash.first);
          hash.second--;
        }
      }
      counts.push_back({hash.first, hash.second});
      n += hash.second;
    }
    for (auto p : counts) {
      // cout << p.first << " " << p.second << endl;
    }
    //cout << oddChar << endl;
    //sort(counts.begin(), counts.end(), [](pair<char, int> &a, pair<char, int> &b) { return a.second > b.second; });
    string current;
    helper(counts, result, current, 0, oddChar, n);
    return result;
  }
};

int main() {
  Solution sol;
  string s = "aaaaa";
  vector<string> result = sol.generatePalindromes(s);
  for (auto res : result)
    cout << res << " ";
  s = "aabbc";
  cout << endl;
  result = sol.generatePalindromes(s);
  for (auto res : result)
    cout << res << " ";
  cout << endl;
  return 0;
}

