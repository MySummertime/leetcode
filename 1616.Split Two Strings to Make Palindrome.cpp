#include <string>

using std::string;


class Solution {
public:
    // two pointers
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

private:
    bool check(const string& a, const string& b) {
        int l = 0, r = a.length() - 1;
        while (l < r && a[l] == b[r]) {
            ++l;
            --r;
        }
        return isPalindrome(a, l, r) || isPalindrome(b, l, r);
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r && s[l] == s[r]) {
            ++l;
            --r;
        }
        return l >= r;
    }
};