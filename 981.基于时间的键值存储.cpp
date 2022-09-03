#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
class TimeMap {
public:
    class tmNode {
    public:
        string k, v;
        int t;

    public:
        tmNode(const string& _k, const string& _v, const int& _t): k(_k), v(_v), t(_t) {}
    };

public:
    // hash map: O(1) set
    // binary search: O(logn) get
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (map.find(key) != map.end()) {
            map[key].push_back(new tmNode(key, value, timestamp));
        }
        else {
            vector<tmNode*> vec {new tmNode(key, value, timestamp)};
            map[key] = vec;
        }
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";
        if (map[key].empty())   return "";
        int len = map[key].size();
        // binary search
        int idx = binarySearch(map[key], 0, len - 1, timestamp);
        if (idx == -1)  return "";
        return map[key][idx]->v;
    }

private:
    int binarySearch(const vector<tmNode*>& vec, int l, int r, const int& target) {
        int m;
        while (l < r) {
            m = l + ((r - l + 1) >> 1);
            if (vec[m]->t <= target) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return vec[r]->t <= target ? r : -1;
    }

private:
    unordered_map<string, vector<tmNode*>> map;
};
