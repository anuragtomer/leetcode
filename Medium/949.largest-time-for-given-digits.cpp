#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    int max_time = -1;

    void check_time(const vector<int> &arr) {
        int hr = arr[0] * 10 + arr[1];
        int min = arr[2] * 10 + arr[3];
        if (hr < 24 && min < 60)
            max_time = max(hr * 60 + min, max_time);
    }

    void permutate(vector<int> &arr, size_t index) {
        if (index == arr.size()) {
            check_time(arr);
            return;
        }

        for (size_t i = index; i < arr.size(); ++i) {
            swap(arr[index], arr[i]);
            permutate(arr, index + 1);
            swap(arr[index], arr[i]);
        }
    }

   public:
    /*
       string largestTimeFromDigits(vector<int> &arr) {
       max_time = -1;
       permutate(arr, 0);
       if (max_time == -1)
       return "";
       else {
       ostringstream streamstr;
       streamstr << setw(2) << setfill('0') << max_time / 60 << ":" << setw(2) << setfill('0') << max_time % 60;
       return streamstr.str();
       }
       }*/
    /*
       Another way using existing next_permutation.
       string largestTimeFromDigits(vector<int> &arr) {
       int max_time = -1;
       sort(arr.begin(), arr.end());
       do {
       int hr = arr[0] * 10 + arr[1];
       int min = arr[2] * 10 + arr[3];
       if (hr < 24 && min < 60) {
       int new_time = hr * 60 + min;
       max_time = max(max_time, new_time);
       }
       } while (next_permutation(arr.begin(), arr.end()));
       if (max_time == -1)
       return "";
       else {
       ostringstream strstream;
       strstream << setw(2) << setfill('0') << max_time / 60 << ":" << setw(2) << setfill('0') << max_time % 60;
       return strstream.str();
       }
       } */
    /* Another smallest way to do the same thing. */
    string largestTimeFromDigits(vector<int> &A) {
        sort(A.begin(), A.end(), greater<int>());
        do
            if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
                return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        while (prev_permutation(A.begin(), A.end()));
        return "";
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    assert(sol.largestTimeFromDigits(arr) == "23:41");
    arr = {5, 5, 5, 5};
    assert(sol.largestTimeFromDigits(arr) == "");
    arr = {0, 0, 0, 0};
    assert(sol.largestTimeFromDigits(arr) == "00:00");
    arr = {0, 0, 1, 0};
    assert(sol.largestTimeFromDigits(arr) == "10:00");
    return 0;
}
