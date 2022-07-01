#include "lib.h"
#include <algorithm>
class Solution {
public:
    int videoStitching(vector <vector <int> >& clips, int T) {
        sort(clips.begin(), clips.end());
        if (clips[0][0] != 0 || clips[clips.size() - 1][1] != T) return -1;
        for (int i = 0; i < clips.size(); i++) {
            lenTillNow = clips[i][1];
            for (int j = i + 1; j <= T; j++) {
                if (clips[j][1] > lenTillNow && clips[j][0] < T);
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector <vector <int> > clips;
    clips.clear();
    clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    int T;
    cin >> T;
    cout << sol.videoStitching(clips, T);
    return 0;
}


/*
 *  Example 1:
 *  Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
 *  Output: 3
 *  Explanation:
 *  We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
 *  Then, we can reconstruct the sporting event as follows:
 *  We cut [1,9] into segments [1,2] + [2,8] + [8,9].
 *  Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
 *
 *  Example 2:
 *  Input: clips = [[0,1],[1,2]], T = 5
 *  Output: -1
 *  Explanation:
 *  We can't cover [0,5] with only [0,1] and [0,2].
 *
 *  Example 3:
 *  Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
 *  Output: 3
 *  Explanation:
 *  We can take clips [0,4], [4,7], and [6,9].
 *
 *  Example 4:
 *  Input: clips = [[0,4],[2,8]], T = 5
 *  Output: 2
 *  Explanation:
 *  Notice you can have extra video after the event ends.
 */
