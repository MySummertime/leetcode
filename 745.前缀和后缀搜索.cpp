#include <vector>
#include <string>

using std::vector;
using std::string;


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
class TrieNode {
public:
    TrieNode* children[26] {nullptr};
    vector<int> idxes;
};


class WordFilter {
public:
    WordFilter(vector<string>& words) {
        forward_trie = new TrieNode();
        reverse_trie = new TrieNode();
        for (int i = 0, len = words.size(); i < len; ++i) {
            add(forward_trie, words[i], i, false);
            add(reverse_trie, words[i], i, true);
        }
    }

    int f(string pref, string suff) {
        return query(pref, suff);
    }

private:
    void add(TrieNode* node, const string& s, int idx, bool reverse) {
        node->idxes.emplace_back(idx);
        for (int len = s.length(), i = (reverse) ? len - 1 : 0, cur; 0 <= i && i < len; i += (reverse) ? -1 : 1) {
            cur = s[i] - 'a';
            if (!node->children[cur]) {
                node->children[cur] = new TrieNode();
            }
            node = node->children[cur];
            node->idxes.emplace_back(idx);
        }
    }

    int query(const string& a, const string& b) {
        TrieNode* ptr = forward_trie;
        // traverse the first trie
        for (int i = 0, len = a.length(), cur; i < len; ++i) {
            cur = a[i] - 'a';
            if (!ptr->children[cur]) {
                return -1;
            }
            ptr = ptr->children[cur];
        }
        vector<int>& l1 = ptr->idxes;
        // traverse the second trie
        ptr = reverse_trie;
        for (int len = b.length(), i = len - 1, cur; i >= 0; --i) {
            cur = b[i] - 'a';
            if (!ptr->children[cur]) {
                return -1;
            }
            ptr = ptr->children[cur];
        }
        vector<int>& l2 = ptr->idxes;
        int len1 = l1.size(), len2 = l2.size();
        for (int i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; ) {
            if (l1[i] > l2[j])  --i;
            else if (l1[i] < l2[j]) --j;
            else {
                return l1[i];
            }
        }
        return -1;
    }

private:
    TrieNode* forward_trie;
    TrieNode* reverse_trie;
};
