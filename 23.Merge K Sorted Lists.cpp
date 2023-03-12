#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Default: std::greater<ListNode.val>
class myComparison {
public:
    int reverse;

public:
    myComparison(bool flag = false): reverse(flag) {}
    bool operator() (ListNode* a, ListNode* b) {
        if (reverse) {
            return a->val < b->val;
        }
        return a->val > b->val;
    }
};

class Solution {
public:
    // monotonic stack
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())  return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, myComparison> pq;
        for (auto it : lists) {
            if (it != nullptr) {
                pq.push(it);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next) {
                pq.push(cur->next);
            }
        }
        return dummy->next;
    }
};