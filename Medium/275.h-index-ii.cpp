#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int hIndex(vector<int> &citations) {
        int size = citations.size(), first = 0, mid, count = size, step;
        while (count > 0) {
            step = count / 2;
            mid = first + step;
            if (citations[mid] < size - mid) {
                first = mid + 1;
                count -= (step + 1);
            } else
                count = step;
        }
        return size - first;
    }
};

int main() {
    Solution sol;
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << sol.hIndex(citations);
    return 0;
}
