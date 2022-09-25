#include <vector>
using namespace std;

class MyCircularQueue {
  vector<int> queue;
  int front, rear, size;

 public:
  MyCircularQueue(int k) {
    front = -1, rear = -1, size = k;
    queue = vector<int>(k);
  }

  bool enQueue(int value) {
    if (not isFull()) {
      rear = (rear + 1) % size;
      queue[rear] = value;
      if (front == -1)
        front = rear;
      return true;
    }
    return false;
  }

  bool deQueue() {
    if (not isEmpty()) {
      if (front == rear) {
        front = -1, rear = -1;
      } else {
        front = (front + 1) % size;
      }
      return true;
    }
    return false;
  }

  int Front() {
    if (not isEmpty())
      return queue[front];
    return -1;
  }

  int Rear() {
    if (not isEmpty())
      return queue[rear];
    return -1;
  }

  bool isEmpty() { return (front == -1) && (front == rear); }

  bool isFull() { return ((front - 1 + size) % size) == rear; }
};
int main() {
  MyCircularQueue *obj = new MyCircularQueue(3);
  assert(obj->enQueue(1));
  assert(obj->enQueue(2));
  assert(obj->enQueue(3));
  assert(not obj->enQueue(4));
  assert(3 == obj->Rear());
  assert(obj->isFull());
  assert(obj->deQueue());
  assert(obj->enQueue(4));
  assert(4 == obj->Rear());
  return 0;
}
