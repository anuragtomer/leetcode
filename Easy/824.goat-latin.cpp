#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
    * @param S: 
    * @return: nothing
    */
  bool isVowel(char ch) {
    switch (ch) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
      default:
        return false;
    }
  }
  string toGoatLatin(string &S) {
    stringstream ss(S);
    string word;
    string result;
    string GOAT = "ma";
    int i = 1;
    while (getline(ss, word, ' ')) {
      if (isVowel(word[0])) {
        result.append(word);
      } else {
        char ch = word[0];
        result.append(string(word.begin() + 1, word.end()));
        result.push_back(ch);
      }
      result.append(GOAT);
      result.append(string(i, 'a'));
      result.append(" ");
      ++i;
    }
    if (result.size() > 0)
      result.pop_back();
    return result;
  }
};
int main() {
  Solution sol;
  string S = "I speak Goat Latin";
  string expected = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
  assert(sol.toGoatLatin(S).compare(expected) == 0);
  S = "The quick brown fox jumped over the lazy dog";
  expected =
    "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
  assert(expected == sol.toGoatLatin(S));
  return 0;
}
