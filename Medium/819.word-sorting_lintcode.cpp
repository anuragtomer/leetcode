#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
    * @param alphabet: the new alphabet
    * @param words: the original string array
    * @return: the string array after sorting
    */
  vector<string> wordSort(string &alphabet, vector<string> &words) {
    unordered_map<char, char> hash;
    char start = 'a';
    for (auto ch : alphabet) {
      hash[ch] = start;
      ++start;
    }
    map<string, pair<string, int>> wordHash;
    for (auto &word : words) {
      string another;
      another.reserve(word.size());
      for (auto &ch : word)
        another.push_back(hash[ch]);
      if (wordHash.find(another) == wordHash.end())
        wordHash[another] = {word, 1};
      else
        wordHash[another].second++;
    }
    vector<string> result;
    result.reserve(words.size());
    for (auto &it : wordHash) {
      while (it.second.second) {
        result.push_back(it.second.first);
        --it.second.second;
      }
    }
    return result;
  }
};
int main() {
  Solution sol;

  return 0;
}

