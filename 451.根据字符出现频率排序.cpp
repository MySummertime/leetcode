#include <string>
#include <queue>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::priority_queue;
using std::unordered_map;


// Default: std::greater<pair<int, int>>
class myComparison {
public:
    bool reverse;

public:
    myComparison(bool flag = false): reverse(flag) {}
    bool operator () (std::pair<int, int>& a, std::pair<int, int>& b) {
        if (reverse) {
            return a.second != b.second ? a.second > b.second : a.first < b.first;
        }
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    }
};

class Solution {
public:
    // priority queue & hash map
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        // get the frequency of each char
        for (const char& c : s) {
            ++mp[c];
        }
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, myComparison> pq;
        // sort the map using priority queue
        for (auto [k, v] : mp) {
            pq.emplace(k, v);
        }
        string ans;
        int cnt;
        char c;
        while (!pq.empty()) {
            cnt = pq.top().second;
            c = pq.top().first;
            pq.pop();
            while (cnt--) {
                ans.push_back(c);
            }
        }
        return ans;
    }
};