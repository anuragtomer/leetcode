#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*string convert(string s, int numRows) {
      if (numRows == 1)
        return s;
      vector<string> rows(numRows);
      int i = 0;
      bool increasing = true;
      for (auto ch: s) {
        rows[i].push_back(ch);
        if(increasing) {
          ++i;
          if (i >= numRows) {
            increasing = !increasing;
            i = i - 2;
          }
        } else {
          --i;
          if (i < 0) {
            increasing = !increasing;
            i = i + 2;
          }
        }
      }
      string result;
      for (auto word: rows)
        result.append(word);
      return result;
    }*/
    string convert(string s, int numRows) {
        int n = s.size();
        string a;
        a.reserve(s.size());
        if (numRows == 1 || n <= numRows)
            return s;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += 2 * (numRows - 1)) {
                a.push_back(s[j]);
                if (i != 0 && i != numRows - 1) {
                    int t = j + 2 * (numRows - 1) - 2 * i;
                    if (t < n)
                        a.push_back(s[t]);
                }
            }
        }
        return a;
    }
};
int main() {
    Solution sol;

    return 0;
}

