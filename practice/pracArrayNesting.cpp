#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution{
    public:
        int nestedArray(vector<int> arr) {
            unordered_map <int, int> h1;
            h1.clear();
            int len = 0;
            int max_len = 0;
            for (int i = 0, j = 0; i < arr.size(); ) {
                unordered_map<int, int> :: iterator got = h1.find(arr[j]);
                if (got == h1.end()) {
                    h1.insert({arr[j], ++len});
                    j = arr[j];
                } else {
                    i++;
                    max_len = (max_len < len)? len: max_len;
                    len = 0;
                    j = i;
                }
            }
            return max_len;
        }
};
int main() {
    Solution sol;
    string input;
    vector<int> arr;
    arr.clear();
    getline(cin, input);
    stringstream s(input);
    string word;
    while(s >> word) {
        // cout << word << " " << stoi(word) << endl;
        arr.push_back(stoi(word));
    }
    cout << sol.nestedArray(arr);
    return 0;
}


