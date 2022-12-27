

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

class Solution {
public:
    // iteration
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        // get the length of the linked list
        int len = 0;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;
        ListNode* prev = nullptr, *nxt;
        cur = p0->next;
        while (len >= k) {
            len -= k;
            for (int i = 0; i < k; ++i) {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            // change nxt to update p0 for each k round
            nxt = p0->next;
            p0->next->next = cur;
            p0->next = prev;
            p0 = nxt;
        }
        return dummy->next;
    }
};