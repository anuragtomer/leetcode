#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    bool didPatternMatch(string word, 
                         string pattern) {
/*        unordered_map < pair <char, char>, int, HASH> forward_hash;
        unordered_map < pair <char, char>, int, HASH> backward_hash;
        unordered_map <char, char> char_to_char;
        char_to_char.clear();
        forward_hash.clear();
        backward_hash.clear();
        for (int i = 0; i < word.size() && i < pattern.size(); i++) {
            unordered_map <char, char> :: iterator it;
            it = char_to_char.find(word[i]);
            if (it == forward_hash.end()) {
                char_to_char.insert({word[i], pattern[i]});
                forward_hash.insert({{word[i], pattern[i]}, i});
                cout << "Storing mapping " << word[i] << "->" << pattern[i] << " in forward_hash\n";
                unordered_map < <char, char>, int> :: iterator it2;
                it2 = backward_hash.find({pattern[i], word[i]});
                if (it2 == backward_hash.end()) {
                    backward_hash.insert({{pattern[i], word[i]}, i});
                    cout << "Storing mapping " << pattern[i] << "->" << word[i] << " in backward_hash\n";
                } else {
                    cout << "Already found mapping between " << word[i] << " and " << pattern[i] << " at " << it2->second << endl;
                    return false;
                }
            } else {
                unordered_map < <char, char>, int> :: iterator it2;
                it2 = backward_hash.find({pattern[i], word[i]});
                if (it2 == backward_hash.end()) {
                    cout << "No mapping found between " << word[i] << " and " << pattern[i] << " in backward_hash\n";
                    return false; // Very unlikely case
                } else {
  */              /*
                    if (it->first != it2->second) {
                        // The index of insertions do not match.
                        cout << "Already found mapping between " << word[i] << " and " << pattern[i] << endl;
                        // Corresponding mapping in forward and backword hash do not match.
                        return false;
                    }
                    */
  /*              }
            }
        }
        return true;
    */
        unordered_map <char, char> forward_map;
        forward_map.clear();
        unordered_map <char, char> backward_map;
        backward_map.clear();
        unordered_map <char, char> :: iterator it, it2;
        for (int i = 0; i < word.size() && i < pattern.size(); i++) {

            it = forward_map.find(word[i]);
            if (it == forward_map.end() ){
                forward_map.insert({word[i], pattern[i]});
            } else if (it->second != pattern[i]) {
                return false;
            }            
            it2 = backward_map.find(pattern[i]);
            if (it2 == backward_map.end()) {
                backward_map.insert({pattern[i], word[i]});           
            } else if (it2->second != word[i]) {
                return false;
            }
        }

        return true;
  
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> output;
        output.clear();
        for (auto &word: words) {
            if (didPatternMatch(word, pattern)) {
                output.push_back(word);
            }
        }
        return output;
    }
};
int main() {
    Solution sol;
    string pattern, input;
    vector <string> words;
    words.clear();
    int count;
    cin >> count;
    while(count > 0) {
        cin >> input;
        words.push_back(input);
        count--;
    }
    cin >> pattern;
    vector <string> output = sol.findAndReplacePattern(words, pattern);
    cout << "Output: " ;
    for (auto &word: output) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}


