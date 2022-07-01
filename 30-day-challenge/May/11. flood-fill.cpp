#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
    Recursive Solution.
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size() || image[sr][sc] == newColor)
            return image;
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        if (sr > 0 && image[sr - 1][sc] == originalColor) {
            image = floodFill(image, sr - 1, sc, newColor);
        }
        if (sr < image.size() - 1 && image[sr + 1][sc] == originalColor) {
            image = floodFill(image, sr + 1, sc, newColor);
        }
        if (sc > 0 && image[sr][sc - 1] == originalColor) {
            image = floodFill(image, sr, sc - 1, newColor);
        }
        if (sc < image[sr].size() - 1 && image[sr][sc + 1] == originalColor) {
            image = floodFill(image, sr, sc + 1, newColor);
        }
        return image;
    }
    */
    void add(stack<pair<int, int>> &pending, int sr, int sc, const vector<vector<int>> &image, int color,
             int newColor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size()) // || color == newColor)
            return;
        if (image[sr][sc] == color && image[sr][sc] != newColor)
            pending.push({sr, sc});
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        stack<pair<int, int>> pending;
        int color = image[sr][sc];
        pending.push({sr, sc});
        while (!pending.empty()) {
            pair<int, int> tp = pending.top();
            pending.pop();
            image[tp.first][tp.second] = newColor;
            add(pending, tp.first - 1, tp.second, image, color, newColor);
            add(pending, tp.first + 1, tp.second, image, color, newColor);
            add(pending, tp.first, tp.second - 1, image, color, newColor);
            add(pending, tp.first, tp.second + 1, image, color, newColor);
        }
        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> filledImage = sol.floodFill(image, 1, 1, 2);
    vector<vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    for (int i = 0; i < filledImage.size(); i++) {
        for (int j = 0; j < filledImage[i].size(); ++j)
            assert(expected[i][j] == filledImage[i][j]);
    }
    image = {{0, 0, 0}, {0, 1, 1}};
    filledImage = sol.floodFill(image, 1, 1, 1);
    expected = {{0, 0, 0}, {0, 1, 1}};
    for (int i = 0; i < filledImage.size(); i++) {
        for (int j = 0; j < filledImage[i].size(); ++j)
            if (expected[i][j] != filledImage[i][j]) {
                cout << "Assert failed at " << i << ", " << j;
                assert(expected[i][j] == filledImage[i][j]);
            }
    }

    return 0;
}
