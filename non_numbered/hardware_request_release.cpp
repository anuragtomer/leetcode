#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
enum current_status { FREE, IN_USE };
enum node_type { T1, T2, T3 };
struct Node {
  int id;
  current_status status;
  node_type type;
  Node(int _id, node_type _type) : id(_id), status(FREE), type(_type) {}
  void printNode() { cout << "{" + to_string(type) + " " + to_string(id) + " " + to_string(status) + "}\n "; }
};
class Cluster {
  mutex m;
  int ID;
  unordered_map<node_type, deque<Node *>> T;
  unordered_map<Node *, deque<Node *>::iterator> in_use_nodes;
  unordered_map<node_type, mutex> nodeMutexes;

 public:
  Cluster() {
    ID = 0;
    T[node_type::T1] = deque<Node *>();
    T[node_type::T2] = deque<Node *>();
    T[node_type::T3] = deque<Node *>();
  }

  Node *request_hardware(node_type nt) {
    for (auto &node : T) {
      if (nt == node.first) {
        nodeMutexes[node.first].lock();
        if (!node.second.empty() && node.second.back()->status == FREE) {
          Node *assigned = node.second.back();
          node.second.pop_back();
          assigned->status = IN_USE;
          node.second.push_front(assigned);
          m.lock();
          in_use_nodes[assigned] = node.second.begin();
          m.unlock();
        } else {
          m.lock();
          Node *newNode = new Node(ID, node.first);
          newNode->status = IN_USE;
          ++ID;
          node.second.push_front(newNode);
          in_use_nodes[newNode] = node.second.begin();
          m.unlock();
        }
        nodeMutexes[node.first].unlock();
        return node.second.front();
      }
    }
    cout << "ERROR: Incorrect type requested: " + to_string(nt) + "\n";
    return nullptr;
  }

  bool release_hardware(Node *node) {
    if (node->status == FREE) {
      cout << "INFO: Node already free: ";
      node->printNode();
      return true;
    }
    node->status = FREE;
    for (auto &nodes : T) {
      if (node->type == nodes.first) {
        nodeMutexes[nodes.first].lock();
        m.lock();
        nodes.second.erase(in_use_nodes[node]);
        nodes.second.push_back(node);
        in_use_nodes.erase(node);
        m.unlock();
        nodeMutexes[nodes.first].unlock();
        return true;
      }
    }
    cout << "ERROR: Incorrect type: ";
    node->printNode();
    return false;
  }
};

void thread_action(Cluster &cluster, node_type type) {
  Node *node = cluster.request_hardware(type);
  cout << "Node received: ";
  node->printNode();
  this_thread::sleep_for(chrono::milliseconds(1000));
  cluster.release_hardware(node);
}

int main() {
  Cluster cluster;
  vector<thread *> threads;
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T1));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T2));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T1));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T3));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T3));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T3));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T2));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T1));
  threads.push_back(new thread(&thread_action, ref(cluster), node_type::T2));
  for (auto t : threads) {
    if (t->joinable())
      t->join();
  }
  return 0;
}

