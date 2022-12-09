class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> unique;
    for (auto &email : emails) {
      string normalized;
      bool local = true, plus = false;
      for (auto &ch : email) {
        if (local) {
          if (ch == '.')
            continue;
          if (ch == '@') {
            normalized.push_back(ch);
            local = false;
          } else if (plus == false && ch == '+') {
            plus = true;
          } else if (not plus)
            normalized.push_back(ch);
        } else
          normalized.push_back(ch);
      }
      unique.insert(normalized);
    }
    return unique.size();
  }
};
