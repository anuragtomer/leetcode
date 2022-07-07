#include <iostream>
#include <unordered_map>
#include <ctime>

using namespace std;

class Solution {
public:

    unordered_map<string, string> forwardHash;
    unordered_map<string, string> backwardHash;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        unordered_map<string, string>::iterator it = forwardHash.find(longUrl);
        if (it != forwardHash.end()) 
            return it->second;
        
        srand(time(NULL));
        int a[6];
        for (int i = 0; i < 6; ++i) {
            a[i] = rand() % 62;
        }
        
        char *char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234567890";
        char str[7];
        for (int i = 0; i < 6; ++i) {
            str[i] = char_set[a[i]];
        }
        str[6] = '\0';
        string stng (str);
        forwardHash.insert(make_pair(longUrl, "http://tinyurl.com/" + stng));
        backwardHash.insert(make_pair("http://tinyurl.com/" + stng, longUrl));
        return stng;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        unordered_map<string, string>::iterator it = backwardHash.find("http://tinyurl.com/" + shortUrl);
        if (it != backwardHash.end())
            return it->second;
        return {};
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution sol;
    string str = "https://leetcode.com/problems/design-tinyurl";
    string str1 = "https://leetcode.com/problems/another_random_string";
    string str2 = "https://leetcode.com/problems/some_random_string";
    string str3 = "https://leetcode.com/problems/anurag_tomer_string";
    cout << "string 1: " << str << endl;
    cout << "string 2: " << str1 << endl;
    cout << "string 3: " << str2 << endl;
    cout << "string 4: " << str3 << endl;
    cout << sol.decode(sol.encode(str)) << endl;
    cout << sol.decode(sol.encode(str1)) << endl;
    cout << sol.decode(sol.encode(str2)) << endl;
    cout << sol.decode(sol.encode(str3)) << endl;
    return 0;
}


