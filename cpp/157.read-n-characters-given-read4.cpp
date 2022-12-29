#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int read4(char *buf) {
    if (last >= sz)
      return 0;
    int readChars = 4;
    if (sz - last < 4)
      readChars = sz - last;
    memcpy(buf, text + last, readChars);
    last = min(last + 4, sz);
    return readChars;
  }

  int last = 0;
  char *text;
  int sz = 0;

 public:
  void setRead4(char *_text, int _n) {
    last = 0;
    text = (char *)malloc(_n);
    memcpy(text, _text, _n);
    sz = _n;
  }

  ~Solution() { free(text); }

  int read(char *buf, int n) {
    char tmp[4];
    int cur = 0;
    int count = 0;
    bool end_of_file = false;
    while (!end_of_file && cur < n) {
      count = read4(tmp);
      end_of_file = count < 4;
      int i = 0;
      while (i < count && cur < n) {
        buf[cur++] = tmp[i++];
      }
    }
    return cur;
  }
};

int main() {
  {
    Solution sol;
    char text[] = "abc";
    char *buffer = text;
    sol.setRead4(buffer, 3);
    char buf[4];
    assert(sol.read(buf, 4) == 3);
    assert(buf[0] == 'a');
    assert(buf[1] == 'b');
    assert(buf[2] == 'c');
  }
  {
    Solution sol;
    char text[] = "abcde";
    char *buffer = text;
    sol.setRead4(buffer, 5);
    char buf[5];
    assert(sol.read(buf, 5) == 5);
    assert(buf[0] == 'a');
    assert(buf[1] == 'b');
    assert(buf[2] == 'c');
    assert(buf[3] == 'd');
    assert(buf[4] == 'e');
  }
  {
    Solution sol;
    char text[] = "abcdABCD1234";
    char *buffer = text;
    sol.setRead4(buffer, 12);
    char buf[12];
    assert(sol.read(buf, 12) == 12);
    assert(buf[0] == 'a');
    assert(buf[1] == 'b');
    assert(buf[2] == 'c');
    assert(buf[3] == 'd');
    assert(buf[4] == 'A');
    assert(buf[5] == 'B');
    assert(buf[6] == 'C');
    assert(buf[7] == 'D');
    assert(buf[8] == '1');
    assert(buf[9] == '2');
    assert(buf[10] == '3');
    assert(buf[11] == '4');
  }
  {
    Solution sol;
    char text[] = "leetcode";
    char *buffer = text;
    sol.setRead4(buffer, 8);
    char buf[5];
    assert(sol.read(buf, 5) == 5);
    assert(buf[0] == 'l');
    assert(buf[1] == 'e');
    assert(buf[2] == 'e');
    assert(buf[3] == 't');
    assert(buf[4] == 'c');
  }
  cout << "Pass";
  return 0;
}
