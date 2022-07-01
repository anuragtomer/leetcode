#include <iostream>
#include <unordered_map>
#include <ctime>

using namespace std;

class Solution {
public:
    unordered_map<string, string> hash_map;
    Solution() {
        hash_map.clear();
        srand((unsigned)time(0));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        int sequence[6];
        for (int i = 0; i < 6; i++) {
            sequence[i] = (rand() % 62) + 1;
        }
        char shortUrlchar[7];
        for (int i = 0; i < 6; i++) {
            shortUrlchar[i] = char_set[sequence[i]];
        }
        shortUrlchar[6] = '\0';
        string shortUrl(shortUrlchar);
        hash_map.insert({"https://tinyurl.com/" + shortUrl, longUrl});
        cout << "ShortURL: " << "https://tinyurl.com/" + shortUrl << endl;
        return "https://tinyurl.com/" + shortUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        unordered_map<string, string> :: iterator got = hash_map.find(shortUrl);
        if (got == hash_map.end())
            return NULL;
        else
            return got->second;
    }
};

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


