#include <string>

using std::string;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Trie {
public:
    Trie(): is_end(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* node = this;
        for (const char& c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (const char& c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return node->is_end;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (const char& c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }

private:
    bool is_end;
    Trie* next[26];
};
