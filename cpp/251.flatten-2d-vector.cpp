#include <algorithm>
#include <iostream>
#include <vector>

#include "lib.hpp"
using namespace std;
using namespace vectors;
class Vector2D {
  vector<vector<int>> vec;
  int rows, cols;

 public:
  Vector2D(vector<vector<int>> _vec) : rows(0), cols(0) {
    for (int i = 0; i < _vec.size(); ++i) {
      if (_vec[i].empty())
        continue;
      vec.push_back(vector<int>());
      for (int j = 0; j < _vec[i].size(); ++j) {
        vec.back().push_back(_vec[i][j]);
      }
    }
  }
  int next() {
    if (rows == vec.size()) {
      return -1;
    }
    int val = vec[rows][cols];
    ++cols;
    if (cols == vec[rows].size()) {
      ++rows;
      cols = 0;
    }
    return val;
  }
  bool hasNext() { return rows != vec.size(); }
};
int main() {
  vector<vector<int>> vec = {{1, 2}, {3}, {4, 5, 6}};
  Vector2D *v2d = new Vector2D(vec);
  assert(v2d->hasNext());
  assert(1 == v2d->next());
  assert(v2d->hasNext());
  assert(2 == v2d->next());
  assert(v2d->hasNext());
  assert(3 == v2d->next());
  assert(v2d->hasNext());
  assert(4 == v2d->next());
  assert(v2d->hasNext());
  assert(5 == v2d->next());
  assert(v2d->hasNext());
  assert(6 == v2d->next());
  assert(not v2d->hasNext());
  vec = {{7, 9}, {5}};
  v2d = new Vector2D(vec);
  assert(v2d->hasNext());
  assert(7 == v2d->next());
  assert(v2d->hasNext());
  assert(9 == v2d->next());
  assert(v2d->hasNext());
  assert(5 == v2d->next());
  assert(not v2d->hasNext());
  vec = {{7, 9}, {}, {8}, {}, {10, 11}, {}};
  v2d = new Vector2D(vec);
  assert(v2d->hasNext());
  assert(7 == v2d->next());
  assert(v2d->hasNext());
  assert(9 == v2d->next());
  assert(v2d->hasNext());
  assert(8 == v2d->next());
  assert(v2d->hasNext());
  assert(10 == v2d->next());
  assert(v2d->hasNext());
  assert(11 == v2d->next());
  assert(not v2d->hasNext());
  return 0;
}
