#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL) {
            if (fast->next == NULL) { return NULL; }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                for (fast = head; fast != slow; fast = fast->next, slow = slow->next);
                return slow;
            }
        }
        return NULL;
    }
};