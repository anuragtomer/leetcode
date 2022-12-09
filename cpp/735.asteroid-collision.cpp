class Solution {
 public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> result;
    auto collision = [](int a, int b) -> bool { return (a > 0 && b < 0); };
    for (auto &ast : asteroids) {
      if (result.empty())
        result.push_back(ast);
      else if (not collision(result.back(), ast))
        result.push_back(ast);
      else {
        bool need_insertion = false;
        while (not result.empty() && collision(result.back(), ast)) {
          if (abs(result.back()) < abs(ast)) {
            result.pop_back();
            need_insertion = true;
          } else if (abs(result.back()) == abs(ast)) {
            result.pop_back();
            need_insertion = false;
            break;
          } else {
            need_insertion = false;
            break;
          }
        }
        if (need_insertion)
          result.push_back(ast);
      }
    }
    return result;
  }
};
