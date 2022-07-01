#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search_char(string J, int from_index, int to_index, char to_search) {
        if (from_index > to_index)
            return false;
        if (from_index == to_index)
            if (J[from_index] != to_search)
                return false;
            else
                return true;
        int mid = (from_index + to_index) / 2;
        if (J[mid] > to_search) { 
            return search_char(J, from_index, (from_index + to_index)/2, to_search);
        } else if (J[mid] < to_search) { 
            return search_char(J, mid + 1, to_index, to_search);
        } else if (J[mid] == to_search) {
            return true;
        }
        return false;
    }
    
    int numJewelsInStones(string J, string S) {
        sort(J.begin(), J.end());
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            char char_to_search = S[i];
            if (search_char(J, 0, J.size(), char_to_search) == true)
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string J = "aA";
    string S = "aAAbbbbB";
    cout << sol.numJewelsInStones(J, S);
    return 0;
}


