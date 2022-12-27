
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

/*
class Solution {
public:
    // recursion
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
*/



class Solution {
public:
    // iteration
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};