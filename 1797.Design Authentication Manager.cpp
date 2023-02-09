#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

// double end linked list
struct Node {
public:
    string token;
    int expiry;
    Node* prev;
    Node* next;

public:
    Node(int _expiry): expiry(_expiry), prev(nullptr), next(nullptr) {}
    Node(string _token, int _expiry): token(_token), expiry(_expiry), prev(nullptr), next(nullptr) {}
    Node(string _token, int _expiry, Node* _prev, Node* _next):
        token(_token), expiry(_expiry), prev(_prev), next(_next) {}
};

class AuthenticationManager {
public:
    unordered_map<string, Node*> mp;
    Node* dummy_head;
    Node* dummy_tail;
    int expiry;

public:
    AuthenticationManager(int timeToLive) {
        this->expiry = timeToLive;
        this->dummy_head = new Node(-1);
        this->dummy_tail = new Node(-1);
        this->dummy_head->next = dummy_tail;
        this->dummy_tail->prev = dummy_head;
    }

    void generate(string tokenId, int currentTime) {
        Node* node = new Node(tokenId, currentTime + this->expiry);
        mp[tokenId] = node;
        Node* last = this->dummy_tail->prev;
        last->next = node;
        node->prev = last;
        node->next = dummy_tail;
        dummy_tail->prev = node;
    }

    void renew(string tokenId, int currentTime) {
        if (mp.find(tokenId) != mp.end() && mp[tokenId]->expiry > currentTime) {
            Node* node = mp[tokenId];
            node->expiry = currentTime + this->expiry;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            Node* last = this->dummy_tail->prev;
            last->next = node;
            node->prev = last;
            node->next = this->dummy_tail;
            this->dummy_tail->prev = node;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        while (this->dummy_head->next->expiry > 0 && this->dummy_head->next->expiry <= currentTime) {
            Node* node = this->dummy_head->next;
            this->dummy_head->next = node->next;
            node->next->prev = node->prev;
            mp.erase(node->token);
            delete node;
        }
        return mp.size();
    }
};
