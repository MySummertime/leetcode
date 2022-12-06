
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)  return nullptr;
        ListNode* dummy_odd = new ListNode();
        ListNode* dummy_even = new ListNode();
        ListNode* odd = dummy_odd;
        ListNode* even = dummy_even;
        bool isOdd = true;
        while (head) {
            // collect odd nodes
            if (isOdd) {
                odd->next = head;
                odd = odd->next;
            }
            // collect even nodes
            else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            isOdd = !isOdd;
        }
        even->next = nullptr;
        odd->next = dummy_even->next;
        return dummy_odd->next;
    }
};