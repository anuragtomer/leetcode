#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    for (auto &c : input) {
        if (c >= 'A' && c <= 'Z')
            c += 32;
        if (c == ' ')
            c = '-';
    }
    input.insert(0, "http://www.leetcode.com/problems/");
    input.push_back('/');
    cout << input << endl;
    return 0;
}