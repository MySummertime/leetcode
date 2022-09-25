#include <vector>
#include <string>


using std::vector;
using std::string;

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
/*
class Trie {
public:
    bool is_leaf;
    Trie* next[26];

public:
    Trie(): is_leaf(false) {
        memset(next, 0, sizeof(next));
    }

    void insertReversely(string word) {
        std::reverse(word.begin(), word.end());
        Trie* node = this;
        for (int i = 0, len = word.length(); i < len; ++i) {
            if (node->next[word[i] - 'a'] == nullptr) {
                node->next[word[i] - 'a'] = new Trie();
            }
            node = node->next[word[i] - 'a'];
        }
        node->is_leaf = true;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        scale = 0;
        waiting.clear();
        for (auto& s : words) {
            root.insertReversely(s);
            scale = scale > s.length() ? scale : s.length();
        }
    }

    bool query(char letter) {
        waiting.insert(waiting.begin(), letter);
        // keep the longest word in the waiting vector
        // because others are useless
        if (waiting.size() > scale) {
            waiting.pop_back();
        }
        Trie* node = &root;
        for (auto it = waiting.begin(); it != waiting.end(); ++it) {
            if (node->is_leaf)  return true;
            if (node->next[*it - 'a'] == nullptr)   return false;
            node = node->next[*it - 'a'];
        }
        return node->is_leaf;
    }

private:
    Trie root;
    vector<char> waiting;
    int scale;
};
*/

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
class Trie {
public:
    bool is_end;
    Trie* children[26];

public:
    Trie(): is_end(false) {
        memset(children, 0, sizeof(children));
    }

    void insert(string s, bool reverse = false) {
        Trie* node = this;
        for (int len = s.length(), i = (reverse) ? len - 1 : 0; 0 <= i && i < len; i += (reverse) ? -1 : 1) {
            if (!node->children[s[i] - 'a']) {
                node->children[s[i] - 'a'] = new Trie();
            }
            node = node->children[s[i] - 'a'];
        }
        node->is_end = true;
    }
};


class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        scale = 0;
        waiting.clear();
        for (const string& s : words) {
            tree.insert(s, true);
            scale = scale > s.length() ? scale : s.length();
        }
    }

    bool query(char letter) {
        waiting.insert(waiting.begin(), letter);
        if (waiting.size() > scale) {
            waiting.pop_back();
        }
        Trie* node = &tree;
        for (auto it = waiting.begin(); it != waiting.end(); ++it) {
            if (node->is_end) {
                return true;
            }
            if (!node->children[*it - 'a']) {
                return false;
            }
            node = node->children[*it - 'a'];
        }
        return node->is_end;
    }

private:
    Trie tree;
    vector<char> waiting;
    int scale;
};