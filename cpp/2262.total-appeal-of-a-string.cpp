/**
The appeal of a string is the number of distinct characters found in the string.

For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "abbca"
Output: 28
Explanation: The following are the substrings of "abbca":
- Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1, 1, and 1 respectively. The sum is 5.
- Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2, and 2 respectively. The sum is 7.
- Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3 respectively. The sum is 7.
- Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
The total sum is 5 + 7 + 7 + 6 + 3 = 28.
Example 2:

Input: s = "code"
Output: 20
Explanation: The following are the substrings of "code":
- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
The total sum is 4 + 6 + 6 + 4 = 20.

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

class Solution {
public:
    /* Not accepted but correct */
    /*
    long long appealSum(string s) {
        vector<bitset<26>> current_level(s.size());
        long long total = 0;
        size_t i = 0;
        for (const char &ch: s) {
            bitset<26> btst;
            ++total;
            btst.set(ch - 'a');
            current_level[i++] = btst;
        }
        while (current_level.size() != 1) {
            vector<bitset<26>> next_level(current_level.size() - 1);
            for (size_t i = 0; i < current_level.size() - 1; ++i) {
                bitset<26> btst = current_level[i] | current_level[i + 1];
                total += btst.count();
                next_level[i] = btst;
            }
            current_level = next_level;
        }
        return total;
    } */
    // https://leetcode.com/problems/total-appeal-of-a-string/solutions/1996390/java-c-python-easy-and-concise-with-explanation
    // Solution 1. O(26n)
    /*
    long long appealSum(string s) {
        vector<int> last(26);
        long res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i + 1;
            for (int j: last)
                res += j;
        }
        return res;
    }*/
    
    // Solution 2. O(n)
    
    long long appealSum(string s) {
        long long result = 0, current = 0;
        vector<long long> prev(26, 0);
        for (size_t i = 0; i < s.size(); ++i) {
            current += i + 1 - prev[s[i] - 'a'];
            prev[s[i] - 'a'] = i + 1;
            result += current;
        }
        return result;
    }
};
