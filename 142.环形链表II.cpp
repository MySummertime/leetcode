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
*/

class Solution {
public:
    // two pointers
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while (slow != head) {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};