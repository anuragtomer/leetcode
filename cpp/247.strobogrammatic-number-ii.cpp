#include <chrono>
#include <unordered_set>

#include "lib.hpp"
using namespace std;
using namespace vectors;
class Solution {
  void findStrobogrammatic(int n, const unordered_map<int, int> &upside,
                           string &flipped, string &current,
                           unordered_set<string> &result) {
    if (n == 0) {
      if (current == flipped) {
        result.insert(current);
        result.insert(flipped);
      }
      return;
    }

    for (auto &mp : upside) {
      current += to_string(mp.first);
      string last = flipped;
      flipped = to_string(mp.second) + flipped;
      findStrobogrammatic(n - 1, upside, flipped, current, result);
      flipped = last;
      current.pop_back();
    }
    return;
  }

 public:
  vector<string> findStrobogrammatic(int n) {
    if (n == 0)
      return {};
    unordered_map<int, int> upside = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
    string current, flipped;
    unordered_set<string> result;
    for (auto &mp : upside) {
      if (mp.first == 0 && n != 1)
        continue;
      current += to_string(mp.first);
      flipped += to_string(mp.second);
      findStrobogrammatic(n - 1, upside, flipped, current, result);
      flipped.pop_back();
      current.pop_back();
    }
    return vector<string>(result.begin(), result.end());
  }
  // Following is faster by miles (2 secs vs 0.00042 secs)
  vector<string> findStrobogrammaticAnother(int n) {
    if (n == 0)
      return {};
    char pairs[5][2] = {
      {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    string s(n, '0');
    vector<string> ans;
    function<void(int)> dfs = [&](int i) {
      if (i == (n + 1) / 2) {
        ans.push_back(s);
        return;
      }
      int j = n - 1 - i;
      for (auto &[a, b] : pairs) {
        if (i == j && a != b)
          continue;
        if (i == 0 && n > 1 && a == '0')
          continue;
        s[i] = a;
        s[j] = b;
        dfs(i + 1);
      }
    };
    dfs(0);
    return ans;
  }
};

int main() {
  Solution sol;
  auto tic = std::chrono::steady_clock::now();
  assert(vectors::match_sorted_vecs(sol.findStrobogrammatic(0), {}));

  assert(
    vectors::match_sorted_vecs(sol.findStrobogrammatic(1), {"0", "1", "8"}));

  assert(vectors::match_sorted_vecs(sol.findStrobogrammatic(2),
                                    {"11", "69", "88", "96"}));
  assert(vectors::match_sorted_vecs(
    sol.findStrobogrammatic(3), {"101", "609", "808", "906", "111", "619",
                                 "818", "916", "181", "689", "888", "986"}));

  assert(vectors::match_sorted_vecs(
    sol.findStrobogrammatic(4),
    {"1001", "6009", "8008", "9006", "1111", "6119", "8118",
     "9116", "1691", "6699", "8698", "9696", "1881", "6889",
     "8888", "9886", "1961", "6969", "8968", "9966"}));
  auto tac = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = tac - tic;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  tic = std::chrono::steady_clock::now();
  assert(vectors::match_sorted_vecs(sol.findStrobogrammaticAnother(0), {}));

  assert(vectors::match_sorted_vecs(sol.findStrobogrammaticAnother(1),
                                    {"0", "1", "8"}));

  assert(vectors::match_sorted_vecs(sol.findStrobogrammaticAnother(2),
                                    {"11", "69", "88", "96"}));
  assert(
    vectors::match_sorted_vecs(sol.findStrobogrammaticAnother(3),
                               {"101", "609", "808", "906", "111", "619", "818",
                                "916", "181", "689", "888", "986"}));

  assert(vectors::match_sorted_vecs(
    sol.findStrobogrammaticAnother(4),
    {"1001", "6009", "8008", "9006", "1111", "6119", "8118",
     "9116", "1691", "6699", "8698", "9696", "1881", "6889",
     "8888", "9886", "1961", "6969", "8968", "9966"}));
  tac = std::chrono::steady_clock::now();
  elapsed_seconds = tac - tic;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  return 0;
}
