#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
/*
class Leaderboard {
  vector<int> scores;
  vector<int> players;
  unordered_map<int, vector<int>::iterator> hash;
  int binarySearch(int key) { return 0; }

 public:
  Leaderboard() {}
  void addScore(int playerId, int score) {
    if (hash.find(playerId) != hash.end()) {
      score += *(hash[playerId]);
      scores.erase(hash[playerId]);
      hash.erase(playerId);
    }
    auto lb = lower_bound(scores.begin(), scores.end(), score);
    if (lb == scores.end()) {
      scores.push_back(score);
      players.push_back(playerId);
      hash[playerId] = scores.end() - 1;
    } else {
      players.insert(players.begin() + distance(scores.begin(), lb), playerId);
      scores.insert(lb, score);
      hash[playerId] = lower_bound(scores.begin(), scores.end(), score);
    }
  }
  int top(int k) {
    int sum = 0;
    for (int i = scores.size() - 1; i >= 0 && k > 0; --i) {
      sum += scores[i];
      if (scores[i] != 0)
        --k;
    }
    return sum;
  }
  void reset(int playerId) {
    if (hash.find(playerId) == hash.end())
      return;
    auto lb = lower_bound(players.begin(), players.end(), playerId);
    scores.erase(scores.begin() + distance(players.begin(), lb));
    players.erase(lb);
    hash.erase(playerId);
  }
};*/
class Leaderboard {
  vector<int> playerIDs;
  vector<int> scores;
  int size;

 public:
  Leaderboard() { size = 0; }

  void addScore(int playerId, int score) {
    if (size == 0) {
      playerIDs.push_back(playerId);
      scores.push_back(score);
    } else {
      int idIndex = distance(playerIDs.begin(), lower_bound(playerIDs.begin(), playerIDs.end(), playerId));
      if (idIndex >= 0) {
        int newScore = scores[idIndex] + score;
        playerIDs.erase(idIndex);
        scores.erase(idIndex);
        int index = binarySearch(scores, newScore);
        if (index < 0)
          index = -index - 1;
        playerIDs.add(index, playerId);
        scores.add(index, newScore);
      } else {
        int index = binarySearch(scores, score);
        if (index < 0)
          index = -index - 1;
        playerIDs.add(index, playerId);
        scores.add(index, score);
      }
    }
    size++;
  }

  int top(int K) {
    K = min(K, size);
    int sum = 0;
    for (int i = 0; i < K; i++)
      sum += scores[i];
    return sum;
  }

  void reset(int playerId) {
    int index = distance(playerIDs.begin(), lower_bound(playerIDs.begin(), playerIDs.end(), playerId));
    playerIDs.erase(playerIDs.begin() + index);
    scores.erase(scores.begin() + index);
    size--;
  }

  int binarySearch(vector<int> list, int key) {
    int size = list.size();
    int low = 0, high = size - 1;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      int num = list[mid];
      if (num == key)
        return mid;
      else if (num > key)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return -low - 1;
  }
};
int main() {
  Leaderboard leader;
  leader.addScore(1, 73);
  leader.addScore(2, 56);
  leader.addScore(3, 39);       // leaderboard = [[1,73],[2,56],[3,39]];
  leader.addScore(4, 51);       // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
  leader.addScore(5, 4);        // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
  assert(73 == leader.top(1));  // returns 73;
  leader.reset(1);              // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
  leader.reset(2);              // leaderboard = [[3,39],[4,51],[5,4]];
  leader.addScore(2, 51);       // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
  assert(141 == leader.top(3)); // returns 141 = 51 + 51 + 39;

  return 0;
}

