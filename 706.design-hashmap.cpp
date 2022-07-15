class MyHashMap {
  struct point {
    bool is_initialized;
    int val;
    point() : is_initialized(false){};
    point(bool _init, int _val) : is_initialized(_init), val(_val){};
  };
  vector<point> data;

 public:
  MyHashMap() {}

  void put(int key, int value) {
    if (data.size() <= key)
      data.resize(key + 1);
    data[key] = {true, value};
  }

  int get(int key) {
    if (key >= data.size() || data[key].is_initialized == false)
      return -1;
    return data[key].val;
  }

  void remove(int key) {
    if (key < data.size())
      data[key].is_initialized = false;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
