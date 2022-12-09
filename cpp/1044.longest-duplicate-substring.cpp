#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int prime = 1e8 - 11; // For mod operations on current hash. Large enough prime number.
    vector<int> power;    // Power is used to retrieve the index^26, so that we don't compute it again and again.
    string validate(int len, string str) {
        // hash map saves a map from 'hash' of the string of length 'len' to the starting index of the substring that have that 'hash'.
        unordered_map<int, vector<int>> hash;
        if (len == 0)
            return "";
        long long current = 0; // This is the running hash of the substring of length 'len'.

        // Create the hash for the current string of length len, starting at index 0.
        for (int i = 0; i < len; ++i)
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        // Push it in hash.
        hash[current] = vector<int>(1, 0); // It starts at index 0.

        // Start the sliding window to find a duplicate substring.
        for (int i = len; i < str.size(); ++i) {
            // Kind of sliding window. Remove hash contribution from the first char(i - len) and add contribution from the new incoming char(i).
            current = ((current - (long long)power[len - 1] * (str[i - len] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;

            if (hash.find(current) == hash.end())
                // If I've not seen this hash before, meaning this is a new substring. Push it into the hash.
                hash[current] = vector<int>(1, i - len + 1); // This substring starts at i - len + 1.
            else {
                // Have seen this hash before. Check if they match. This is to double check false positive cases.
                for (auto it : hash[current])
                    if (str.substr(it, len).compare((str.substr(i - len + 1, len))) == 0)
                        return str.substr(it, len);
                // This is a new string with same hash. Push its starting index in hash.
                hash[current].push_back(i - len + 1);
            }
        }
        // Could not find any substring which is duplicate.
        return "";
    }

   public:
    string longestDupSubstring(string S) {
        string answer = "";
        power = vector<int>(S.size(), 1);
        for (int i = 1; i < S.size(); ++i)
            power[i] = (power[i - 1] * 26) % prime;

        int low = 0, high = S.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            string temp = validate(mid, S);
            if (temp.size() == 0)
                high = mid - 1;
            else {
                if (temp.size() > answer.size())
                    answer = temp;
                low = mid + 1;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    string S = "banana";
    assert("ana" == sol.longestDupSubstring(S));
    S = "abcd";
    assert("" == sol.longestDupSubstring(S));
    return 0;
}
