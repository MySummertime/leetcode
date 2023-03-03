#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

    }
};

class Solution {
public:
    // hash map
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> ump;
        for (const string& name : names) {
            if (ump.find(name) != ump.end()) {
                for (int k = ump[name] + 1; ; ++k) {
                    string new_name = name + "(" + std::to_string(k) + ")";
                    if (ump.find(new_name) == ump.end()) {
                        res.push_back(new_name);
                        ump[name] = k;
                        ump[new_name] = 0;
                        break;
                    }
                }
            }
            else {
                res.push_back(name);
                ump[name] = 0;
            }
        }
        return res;
    }
};