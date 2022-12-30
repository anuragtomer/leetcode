#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseWords(string str) {
    stringstream ss(str);
    string word;
    string result;
    stack<string> words;
    while (getline(ss, word, ' ')) {
      words.push(word);
    }
    while (not words.empty()) {
      result += words.top();
      words.pop();
      result.push_back(' ');
    }
    if (not result.empty()) {
      result.pop_back();
    }
    return result;
  }
  string reverseWordsInPlace(string str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
      swap(str[i], str[j]);
    }
    int i = 0, n = str.size();
    while (i < n) {
      int j = i;
      while (j < n && str[j] != ' ')
        ++j;
      for (int k = i, l = j - 1; k < l; ++k, --l) {
        swap(str[k], str[l]);
      }
      i = j + 1;
    }
    return str;
  }
};

int main() {
  Solution sol;
  assert(sol.reverseWords("the sky is blue") == "blue is sky the");
  assert(sol.reverseWords("a b c") == "c b a");
  assert(sol.reverseWordsInPlace("the sky is blue") == "blue is sky the");
  assert(sol.reverseWordsInPlace("a b c") == "c b a");
  return 0;
}
