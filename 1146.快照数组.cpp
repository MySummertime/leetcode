
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::map;
using std::unordered_map;


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
class SnapshotArray {
public:
    SnapshotArray(int length) {}

    void set(int index, int val) {
        m[index][cur_snap] = val;
    }

    int snap() {
        return cur_snap++;
    }

    int get(int index, int snap_id) {
        // upper_bound: search for the first element greater than snap_id
        // if return vec[index].end(), then no element is greater;
        // we return vec[index].end() - 1, which is the element less than or equal to snap_id;
        auto it = m[index].upper_bound(snap_id);
        return it == m[index].begin() ? 0 : std::prev(it)->second;
    }

private:
    unordered_map<int, map<int, int>> m;
    int cur_snap = 0;
};