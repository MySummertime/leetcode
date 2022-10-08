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
    // fast & slow pointers
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (true) {
            if (!fast || !fast->next)   return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            // two pointers meet at the first time
            if (fast == slow) {
                break;
            }
        }
        // two pointers meet at the second time
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};