#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  string arrangeWords(string text) {
    stringstream ss(text);
    map<int, vector<string>> input;
    string word;
    while (getline(ss, word, ' '))
      input[word.size()].push_back(word);
    text.clear();
    for (auto it : input) {
      for (auto _inp : it.second) {
        if (text.empty()) {
          if ('a' <= _inp[0] && _inp[0] <= 'z')
            _inp[0] -= 32;
        } else {
          if ('A' <= _inp[0] && _inp[0] <= 'Z')
            _inp[0] += 32;
        }
        text.append(_inp);
        text.push_back(' ');
      }
    }
    if (not text.empty())
      text.pop_back();
    return text;
  }
};

int main() {
  Solution sol;

  return 0;
}
