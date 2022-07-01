/*
 * Given a positive integer N, find and return the longest distance between 
 * two consecutive 1's in the binary representation of N.
 * If there aren't two consecutive 1's, return 0.
 * 
 * Example:
 * ========
 * Input: 22
 * 
 * Output: 2
 * 
 * Explanation:
 * 22 in binary is 0b10110.
 * In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
 * The first consecutive pair of 1's have distance 2.
 * The second consecutive pair of 1's have distance 1.
 * The answer is the largest of these two distances, which is 2.
 */

#include <iostream>

using namespace std;

class Solution{
    public:
        int binaryGap(int N) {
            int max = 0;
            int distance = 0;
            bool foundOneBit = false;
            int bit;
            while(N) {
                bit = N % 2;
                N /= 2;
                if (bit == 1) {
                    if (foundOneBit == true) {
                        // I'm searching for a neighbor and found it.
                        if (max < distance)
                            max = distance;
                        distance = 1;
                    } else {
                        foundOneBit = true;
                        if (distance == 0) {
                            // This is the case of beginning to find next neighbor 1.
                            // Do nothing.
                            distance++; // Hope we find next 1 in next cycle.
                        } else {
                            // 
                        }
                    }
                } else {
                    if (foundOneBit == true) {
                        distance++;
                    }
                }
            }
            return max;
        }
};
int main() {
    Solution sol;
    int num;
    cin >> num;
    cout << sol.binaryGap(num);
    return 0;
}


