

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
class Solution {
public:
    // fast & slow pointer
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;
        ListNode* slow = head, *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
*/

class Solution {
public:
    // two pointers
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)   return true;
        }
        return false;
    }
};