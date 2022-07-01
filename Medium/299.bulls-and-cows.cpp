#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string getHint(string secret, string guess) {
        /*
        unordered_map<char, int> hash;
        for (auto ch: secret) {
          hash[ch]++;
        }
        int A = 0, B = 0;
        for (int i = 0; i < guess.size(); ++i) {
          if (guess[i] == secret[i]) {
            hash[guess[i]]--;
            ++A;
          }
        }
        for (int i = 0; i < guess.size(); ++i) {
          if (guess[i] != secret[i] && hash[guess[i]] > 0) {
            ++B;
            --hash[guess[i]];
          }
        }
        return to_string(A) + "A" + to_string(B) + "B";
        */

        int bulls = 0;
        int cows = 0;
        vector<int> numbers(10, 0);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i])
                bulls++;
            else {
                if (numbers[secret[i] - '0'] < 0)
                    cows++;
                numbers[secret[i] - '0']++;
                if (numbers[guess[i] - '0'] > 0)
                    cows++;
                numbers[guess[i] - '0']--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution sol;

    return 0;
}

