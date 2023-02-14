#include <string>

using std::string;


class Solution {
public:
    // simulate
    string addBinary(string a, string b) {
        int alen = a.length(), blen = b.length();
        if (alen > blen)    return addBinary(b, a);
        // align both strings by filling '0' in the shorter
        while (alen < blen) {
            a = '0' + a;
            ++alen;
        }
        // operate addition bit by bit
        for (int i = alen - 1; i; --i) {
            a[i] = a[i] - '0' + b[i];
            if (a[i] >= '2') {
                a[i] = (a[i] - '0') % 2 + '0';
                a[i - 1] += 1;
            }
        }
        // deal with the highest bit alone
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= '2') {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};