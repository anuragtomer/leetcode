#include <cassert>
#include <set>

using namespace std;

class ExamRoom {
  int size;
  set<int> seated;

 public:
  ExamRoom(int n) { size = n; }

  int seat() {
    if (seated.size() >= size) {
      // If we have filled all seats, return -1 or crash.
      return -1;
    }
    int position = 0, distance = 0;
    if (seated.empty()) {
      // If room is empty, seat the student at 0th desk.
      seated.insert(position);
      return position;
    }
    auto it = seated.begin();
    distance = *it;
    if (distance == 0) {
      it = next(it);
    }
    while (it != seated.end()) {
      // Find the mid point between current points.
      int curr_distance = (*it - *prev(it)) / 2;
      if (curr_distance > distance) {
        // If this seat distance is farther than earlier distance, we would
        // seat then next student here.
        distance = curr_distance;
        position = *prev(it) + distance;
      }
      it = next(it);
    }
    if (distance < (size - 1) - *(seated.rbegin())) {
      // If there was some student seated at last position, and they left,
      // it might be better to seat the new student here.
      position = size - 1;
    }
    seated.insert(position);
    return position;
  }

  void leave(int p) { seated.erase(p); }
};

int main() {
  ExamRoom room(10);
  assert(room.seat() == 0);
  assert(room.seat() == 9);
  assert(room.seat() == 4);
  assert(room.seat() == 2);
  room.leave(4);
  assert(room.seat() == 5);
  return 0;
}

