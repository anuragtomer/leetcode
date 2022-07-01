#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int sz = 14;
int current = 0;
char *mainBuf;
int read4(char *buf) {
    if (sz - current >= 4) {
        memcpy(buf, mainBuf + current, 4);
        current += 4;
        return 4;
    } else {
        memcpy(buf, mainBuf + current, sz - current);
        int temp = sz - current;
        current = sz;
        return temp;
    }
}

class Solution {
   private:
    char *temp_buf;
    int offset;
    int lastRead;

   public:
    Solution() {
        temp_buf = (char *)malloc(4 * sizeof(temp_buf));
        offset = 0;
        lastRead = 0;
    }
    ~Solution() { free(temp_buf); }
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        int totalChars = 0;
        while (totalChars < n) {
            if (offset == lastRead) {
                lastRead = read4(temp_buf);
                offset = 0;
            }

            if (lastRead == 0)
                return totalChars;

            while (offset < lastRead && totalChars < n)
                buf[totalChars++] = temp_buf[offset++];
        }
        return totalChars;
    }
};

int main() {
    Solution sol;
    mainBuf = (char *)malloc(sizeof(mainBuf) * sz + 1);
    string src = "filetestbuffer";
    memcpy(mainBuf, src.c_str(), 14);
    char *buf = (char *)malloc(6 * sizeof(buf));
    int num = sol.read(buf, 6);
    char dst[7] = "filete";
    assert(0 == memcmp(buf, dst, num));
    free(buf);

    buf = (char *)malloc(5 * sizeof(buf));
    num = sol.read(buf, 5);
    char dst2[6] = "stbuf";
    assert(0 == memcmp(buf, dst2, num));
    free(buf);

    buf = (char *)malloc(4 * sizeof(buf));
    num = sol.read(buf, 4);
    char dst3[5] = "fer";
    assert(0 == memcmp(buf, dst3, num));
    free(buf);

    buf = (char *)malloc(3 * sizeof(buf));
    num = sol.read(buf, 3);
    char dst4[4] = "";
    assert(0 == memcmp(buf, dst4, num));
    free(buf);

    buf = (char *)malloc(2 * sizeof(buf));
    num = sol.read(buf, 2);
    char dst5[3] = "";
    assert(0 == memcmp(buf, dst5, num));
    free(buf);

    buf = (char *)malloc(1 * sizeof(buf));
    num = sol.read(buf, 1);
    char dst6[2] = "";
    assert(0 == memcmp(buf, dst6, num));
    free(buf);
    return 0;
}

