#include <iostream>
#include <regex>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        for (auto ch : s) {
            if (ch != delimiter)
                token.push_back(ch);
            else {
                tokens.push_back(token);
                token = "";
            }
        }
        tokens.push_back(token);
        return tokens;
    }

   public:
    string validIPAddress(string IP) {
        vector<string> tokens = split(IP, '.');
        if (tokens.size() == 4) {
            for (auto token : tokens) {
                if (token[0] == '0')
                    if (token.size() != 1)
                        return "Neither";
                    else {
                        if (token.size() == 0 || token.size() > 3)
                            return "Neither";
                        for (auto ch : token)
                            if (ch > '9' || ch < '0')
                                return "Neither";
                        int num = stoi(token);
                        if (num <= 0 || num >= 256)
                            return "Neither";
                    }
            }
            return "IPv4";
        } else {
            tokens = split(IP, ':');
            string hexadecimal = "0123456789abcdefABCDEF";
            if (tokens.size() != 8)
                return "Neither";
            for (auto token : tokens) {
                if (token.size() > 4 || token.size() == 0)
                    return "Neither";
                for (auto ch : token) {
                    if (hexadecimal.find(ch) == string::npos)
                        return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};

int main() {
    Solution sol;
    assert("Neither" == sol.validIPAddress("256.256.256.256"));
    assert("IPv4" == sol.validIPAddress("172.16.254.1"));
    assert("IPv6" == sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"));
    assert("Neither" == sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"));
    assert("Neither" == sol.validIPAddress("1e1.4.5.6"));
    return 0;
}
