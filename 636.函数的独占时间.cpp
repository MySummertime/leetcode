
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using std::vector;
using std::string;
using std::stack;
using std::stringstream;

struct Log {
    int id;
    string status;
    int timestamp;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> stk;
        for (const string& i : logs) {
            Log item = getLog(i);
            if (item.status == "start") {
                stk.push(item);
            }
            else {
                int time = item.timestamp - stk.top().timestamp + 1;
                times[item.id] += time;
                stk.pop();
                if (!stk.empty()) {
                    times[stk.top().id] -= time;
                }
            }
        }
        return times;
    }

private:
    Log getLog(const string& s) {
        stringstream ss(s);
        string id, start, time;
        std::getline(ss, id, ':');
        std::getline(ss, start, ':');
        std::getline(ss, time, ':');
        return {std::stoi(id), start, std::stoi(time)};
    }
};