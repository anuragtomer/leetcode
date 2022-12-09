#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Logger {
    unordered_map<string, int> lastLogTime;
    int duration = 0;

   public:
    Logger() { duration = 10; }
    bool shouldPrintMessage(int time, string msg) {
        if (lastLogTime.find(msg) == lastLogTime.end()) {
            lastLogTime[msg] = time;
            return true;
        } else if (time - lastLogTime[msg] >= duration) {
            lastLogTime[msg] = time;
            return true;
        }
        return false;
    }
};

int main() {
    Logger *logger = new Logger();
    assert(logger->shouldPrintMessage(1, "foo"));
    assert(logger->shouldPrintMessage(2, "bar"));
    assert(!logger->shouldPrintMessage(3, "foo"));
    assert(!logger->shouldPrintMessage(8, "bar"));
    assert(!logger->shouldPrintMessage(10, "foo"));
    assert(logger->shouldPrintMessage(11, "foo"));
    return 0;
}

