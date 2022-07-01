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
    int i = 0;
    while (i < n) {
      char input[4];
      int count = read4(input);
      if (count == 0)
        return i;
      if (n - i < count)
        count = n - i;
      memcpy(buf + i, input, count);
      i += count;
    }
    return i;
  }
};

int main() {
  Solution sol;
  char text[15] = "filetextbuffer";
  char *buffer = text;
  char buf[4];
  sol.setRead4(buffer, 14);
  cout << sol.read(buf, 20) << endl;
  cout << buf;
  return 0;
}

