#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
class SnapshotArray {
 public:
  SnapshotArray(int length) {
    updates.resize(length);
    current = 0;
  }

  void set(int index, int val) {
    if (!updates[index].empty() && updates[index].back().first == current)
      updates[index].back().second = val;
    else
      updates[index].push_back({current, val});
  }

  int snap() { return current++; }

  int get(int index, int snap_id) {
    int idx = upper_bound(updates[index].begin(), updates[index].end(),
                          make_pair(snap_id, INT_MAX)) -
              updates[index].begin();
    if (idx == 0) return 0;
    return updates[index][idx - 1].second;
  }

 private:
  vector<vector<pair<int, int>>> updates;
  int current;
};
// class SnapshotArray {
//   struct PIT {
//     int snap_id;
//     int val;
//   };

//   struct {
//     bool operator()(const PIT &lhs, const PIT &rhs) {
//       return lhs.snap_id < rhs.snap_id;
//     }
//   } pit_comparator;

//   int current_snapshot_id;
//   vector<vector<PIT>> data;

//  public:
//   SnapshotArray(int length) {
//     current_snapshot_id = 0;
//     data = vector<vector<PIT>>(length);
//   }

//   /**
//    * @brief Sets value at index to val.
//    *
//    * @param index Index to replace.
//    * @param val   Value to replace with.
//    */
//   void set(int index, int val) {
//     if (not data[index].empty() &&
//         data[index].back().snap_id == current_snapshot_id) {
//       data[index].back().val = val;
//     } else {
//       data[index].push_back({current_snapshot_id, val});
//     }
//   }

//   /**
//    * @brief Gets the value in snap_id at index.
//    *
//    * @param snap_id Snapshot id to search value of.
//    * @param index   Index whose value is to be returned.
//    * @return int    Value at index in snap_id snapshot.
//    */
//   int get(int snap_id, int index) {
//     int snapshot_index = upper_bound(data[index].begin(), data[index].end(),
//                                      PIT{snap_id, INT_MAX}, pit_comparator) -
//                          data[index].begin();
//     if (snapshot_index == 0) {
//       return 0;
//     }
//     return data[index][snapshot_index - 1].val;
//   }

//   /**
//    * @brief Takes a snapshot. Returns current Snapshot ID;
//    *
//    * @return int : Snapshot ID.
//    */
//   int snap() {
//     // ++current_snapshot_id;
//     return current_snapshot_id++;
//   }
// };

int main() {
  {
    SnapshotArray snapshotArr(3);
    snapshotArr.set(0, 5);
    assert(0 == snapshotArr.snap());
    snapshotArr.set(0, 6);
    assert(5 == snapshotArr.get(0, 0));
  }
  {
    SnapshotArray snapshotArr(2);
    snapshotArr.set(0, 12);
    snapshotArr.snap();
    snapshotArr.snap();
    assert(0 == snapshotArr.get(1, 0));
    assert(0 == snapshotArr.get(1, 0));
    snapshotArr.snap();
    snapshotArr.snap();
  }
  return 0;
}