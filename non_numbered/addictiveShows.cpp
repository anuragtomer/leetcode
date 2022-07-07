#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  struct data {
    string show;
    int id;
    int episode;
  };
  data parseLog(string &log) {
    stringstream ss(log);
    string strid, strepisode;
    data current;
    getline(ss, current.show, ',');
    getline(ss, strid, ',');
    current.id = stoi(strid);
    getline(ss, strepisode, ',');
    current.episode = stoi(strepisode);
    return current;
  }

 public:
  unordered_map<string, int> addictive(vector<string> &logs) {
    unordered_map<string, vector<int>> perShow;
    for (auto log : logs) {
      data current = parseLog(log);
      if (perShow[current.show].empty()) {
        perShow[current.show] = vector<int>(10, 0);
      }
      perShow[current.show][current.episode]++;
    }
    unordered_map<string, int> addiction;
    for (auto show : perShow) {
      addiction[show.first] = 10;
      for (int i = 0; i < 9; ++i) {
        if (show.second[i] * 0.7 > show.second[9]) {
          addiction[show.first] = i + 1;
          break;
        }
      }
    }
    return addiction;
  }
};

int main() {
  Solution sol;

  return 0;
}

