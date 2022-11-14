#include <string>
#include <queue>

using std::string;
using std::deque;


class Solution {
public:
    // deque
    string reverseWords(string s) {
        int len = s.length();
        // truncate leading and trailing spaces
        int l = 0, r = len - 1;
        while (l <= r && s[l] == ' ')   ++l;
        while (l <= r && s[r] == ' ')   --r;
        deque<string> deq = set(s, l, r);
        string ans = get(deq);
        return ans;
    }

private:
    deque<string> set(string& s, int& l, int& r) {
        deque<string> deq;
        string word;
        while (l <= r) {
            char c = s[l];
            // find a word
            if (word.length() && c == ' ') {
                deq.push_front(word);
                word.clear();
            }
            // a word isn't completed
            else if (c != ' ') {
                word += c;
            }
            ++l;
        }
        deq.push_front(std::move(word));
        return deq;
    }

    string get(deque<string>& deq) {
        string ans;
        while (!deq.empty()) {
            ans.append(deq.front());
            deq.pop_front();
            if (!deq.empty()) {
                ans.append(" ");
            }
        }
        return ans;
    }
};