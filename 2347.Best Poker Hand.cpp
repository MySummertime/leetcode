#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;


class Solution {
public:
    // hash map
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> suit_mp;
        // count the suit
        for (const char& ch : suits) {
            ++suit_mp[ch];
        }
        // ['Flush', 'Three of a Kind', 'Pair', 'High Card']
        for (auto itr = suit_mp.begin(); itr != suit_mp.end(); ++itr) {
            if (itr->second == 5) {
                return "Flush";
            }
        }
        unordered_map<int, int> rank_mp;
        // count the rank
        for (const int& i : ranks) {
            ++rank_mp[i];
        }
        bool pair = false;
        for (auto itr = rank_mp.begin(); itr != rank_mp.end(); ++itr) {
            if (itr->second >= 3) {
                return "Three of a Kind";
            }
            if (itr->second == 2) {
                pair = true;
            }
        }
        if (pair)   return "Pair";
        return "High Card";
    }
};