#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void helper(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldColor ||
        image[sr][sc] == newColor)
      return;
    image[sr][sc] = newColor;
    helper(image, sr + 1, sc, newColor, oldColor);
    helper(image, sr - 1, sc, newColor, oldColor);
    helper(image, sr, sc + 1, newColor, oldColor);
    helper(image, sr, sc - 1, newColor, oldColor);
  }

 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
      return image;
    helper(image, sr, sc, newColor, image[sr][sc]);
    return image;
  }
};

int main() {
  Solution sol;

  return 0;
}

