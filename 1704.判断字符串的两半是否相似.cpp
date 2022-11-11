#include <string>

using std::string;


class Solution {
public:
    // counting
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.length() >> 1);
        string b = s.substr(s.length() >> 1);
        int cnta = getVowelCnt(a);
        int cntb = getVowelCnt(b);
        return cnta == cntb;
    }

private:
    int getVowelCnt(const string& s) {
        int cnt = 0;
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (BANNED.find(s[i]) != string::npos) {
                ++cnt;
            }
        }
        return cnt;
    }

private:
    string BANNED = "aeiouAEIOU";
};