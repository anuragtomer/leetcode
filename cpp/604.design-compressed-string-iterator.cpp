#include <string>
using namespace std;

class StringIterator {
  string str;
  char ch;
  int index;
  int size;
  int count;
  bool move_forward() {
    if (index >= size)
      return false;
    ch = str[index];
    ++index;
    set_count();
    return true;
  }
  void set_count() {
    count = 0;
    while (index < str.size() && str[index] >= '0' && str[index] <= '9') {
      count = count * 10 + str[index] - '0';
      ++index;
    }
  }

 public:
  StringIterator(string cs) : str(cs) {
    index = 0;
    size = str.size();
    ch = str[index];
    ++index;
    set_count();
  }
  char next() {
    if (count > 0 || move_forward()) {
      --count;
      return ch;
    }
    return ' ';
  }
  bool hasNext() { return not(index >= size && count <= 0); }
};

int main() {
  StringIterator *iterator = new StringIterator("L1e2t1C1o1d1e1");

  assert('L' == iterator->next());
  assert('e' == iterator->next());
  assert('e' == iterator->next());
  assert('t' == iterator->next());
  assert('C' == iterator->next());
  assert('o' == iterator->next());
  assert('d' == iterator->next());
  assert(iterator->hasNext());
  assert('e' == iterator->next());
  assert(not iterator->hasNext());
  assert(' ' == iterator->next());
  return 0;
}
