class Solution {
  char getNext(const string &s, int &i) {
    char next;
    if (i + 2 < s.size() && s[i + 2] == '#') {
      next = 96 + ((s[i] - '0') * 10) + (s[i + 1] - '0');
      i += 3;
    } else {
      next = 96 + (s[i] - '0');
      ++i;
    }
    return next;
  }

 public:
  string freqAlphabets(string s) {
    string result;
    for (int i = 0; i < s.size();) {
      result.push_back(getNext(s, i));
    }
    return result;
  }
};
