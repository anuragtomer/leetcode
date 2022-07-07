#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
    public:
        int lastOccurance(char a, string S) {
            int i = S.size();
            for (i = S.size() - 1; i >= 0; i--) {
                if (S[i] == a)
                    return i;
            }
            assert(i >= 0);
            return -1;
        }

        void removeNulls(vector<vector<int>> &array) {
            int j = 0;
            for (int i = 0; i < 26; i++) {
                if (array[i][0] != -1) {
                    array[j][0] = array[i][0];
                    array[j][1] = array[i][1];
                    j++;
                }
            }
            array.resize(j);
        }

        void printarray(vector<vector<int>> start_end, int lb, int ub) {
            for (int i = lb; i <= ub; i++) {
                cout << "(" << start_end[i][0] << ", " << start_end[i][1] << ")\n";
            }
        }

        void merge(vector<vector<int>> &start_end, int lb1, int ub1, int lb2, int ub2) {
            vector<vector<int>> _start_end(start_end.size(), vector<int> (2));
            int lb = lb1;
            int start = lb1;
            int end = ub2;
            while (((ub1 - lb1) >= 0) && ((ub2 - lb2) >= 0)) {
                if (start_end[lb1][0] > start_end[lb2][0]) {
                    _start_end[lb][0] = start_end[lb2][0];
                    _start_end[lb][1] = start_end[lb2][1];
                    lb2++;
                    lb++;
                } else {
                    _start_end[lb][0] = start_end[lb1][0];
                    _start_end[lb][1] = start_end[lb1][1];
                    lb1++;
                    lb++;
                }
            }
            while ((ub1 - lb1) >= 0) {
                _start_end[lb][0] = start_end[lb1][0];
                _start_end[lb][1] = start_end[lb1][1];
                lb1++;
                lb++;
            }
            while ((ub2 - lb2) >= 0) {
                _start_end[lb][0] = start_end[lb2][0];
                _start_end[lb][1] = start_end[lb2][1];
                lb2++;
                lb++;
            }
            for (int i = start; i <= end; i++) {
                start_end[i][0] = _start_end[i][0];
                start_end[i][1] = _start_end[i][1];
            }
        }

        void mergeSortOnEnd(vector<vector<int>> &start_end, int lb, int ub) {
            if (lb == ub) {
                return;
            } else if (lb + 1 == ub) {
                // There are just 2 elements. Sort and return.
                if (start_end[lb][0] > start_end[ub][0]) {
                    int temp0 = start_end[lb][0];
                    int temp1 = start_end[lb][1];
                    start_end[lb][0] = start_end[ub][0];
                    start_end[lb][1] = start_end[ub][1];
                    start_end[ub][0] = temp0;
                    start_end[ub][1] = temp1;
                }
            } else {
                int mid = (lb + ub) / 2;
                mergeSortOnEnd(start_end, lb, mid);
                mergeSortOnEnd(start_end, mid + 1, ub);
                merge(start_end, lb, mid, mid+1, ub);
            }
        }
        
        vector<int> findPartitions(vector<vector<int>> start_end) {
            int least = start_end[0][0];
            int last = start_end[0][1];
            vector <int> output;
            output.clear();
            for (int i = 1; i < start_end.size(); i++) {
                if (start_end[i][0] > last) {
                    output.push_back(last - least + 1);
                    least = start_end[i][0];
                    last = start_end[i][1];
                } else if (start_end[i][0] < last) {
                    last = (last < start_end[i][1]) ? start_end[i][1]: last;
                }
            }
            output.push_back(last - least + 1);
            return output;
        }

        vector<int> partitionLabels(string S) {
            vector <int> output;
            vector<vector<int>> start_end(26, vector<int>(2));
            for (int i = 0; i < 26; i++) {
                start_end[i] = {-1, -1};
            }

            char a = S[0];
            for (int i = 0; i < S.size(); i++) {
                if (start_end[S[i] - 'a'][0] == -1) {
                    a = S[i];
                    int idx = lastOccurance(a, S);
                    start_end[S[i] - 'a'][0] = i;
                    start_end[S[i] - 'a'][1] = idx;
                }
            }
            removeNulls(start_end);
            mergeSortOnEnd(start_end, 0, start_end.size() - 1);
            output = findPartitions(start_end);
            return output;
        }
};
int main() {
    Solution sol;
    vector<int> partition;
    partition = sol.partitionLabels("abbaabccdc");
    for (int i = 0; i < partition.size(); i++)
        cout << partition[i] << " ";
    return 0;
}


