#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    // hash map && sort
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        // key: name, value: time stamp by minute
        unordered_map<string, vector<int>> mp;
        for (int i = 0, len = keyName.size(); i < len; ++i) {
            if (mp.find(keyName[i]) == mp.end()) {
                mp[keyName[i]] = {};
            }
            mp[keyName[i]].emplace_back(getMin(keyTime[i]));
        }
        vector<string> ans;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            vector<int> time = itr->second;
            // sort each time vector
            std::sort(time.begin(), time.end(), std::less<>());
            for (int i = 0, len = time.size(); i < len - 1; ++i) {
                if (time[i + 1] - time[i] <= 60) {
                    ans.emplace_back(itr->first);
                    break;
                }
            }
        }
        std::sort(ans.begin(), ans.end(), std::less<>());
        return ans;
    }

private:
    int getMin(string tstr) {
        int hour, min;
        hour = 10 * (tstr[0] - '0') + (tstr[1] - '0');
        min = 10 * (tstr[3] - '0') + (tstr[4] - '0');
        return 60 * hour + min;
    }
};