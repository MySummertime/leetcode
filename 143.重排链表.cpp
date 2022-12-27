
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // two pointers
    void reorderList(ListNode* head) {
        // get the middle node
        ListNode* mid = getMiddleNode(head);
        // get the tailing head
        ListNode* head2 = reverseLinkedList(mid);
        ListNode* nxt, *nxt2;
        while (head2->next) {
            nxt = head->next;
            nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt;
            head = nxt;
            head2 = nxt2;
        }
    }

private:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* cur = head, *prev = nullptr, *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};