#include "lib.h"

class Solution {
public:
    bool divisorGame(int N) {
        return (N % 2 == 0);
    }
};

int main(){
    Solution sol;
    int N;
    cin >> N;
    if (sol.divisorGame(N)) cout << "true";
    else cout << "false";
    return 0;
}
