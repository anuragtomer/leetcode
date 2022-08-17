class Solution {
 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    unordered_set<string> set;
    vector<string> morse = {
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    for (auto &word : words) {
      string code;
      for (auto ch : word)
        code.append(morse[ch - 'a']);
      set.insert(code);
    }
    return set.size();
  }
};
