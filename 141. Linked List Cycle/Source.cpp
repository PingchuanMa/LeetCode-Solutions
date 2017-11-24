#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL) {
            if (fast->next == NULL) { return false; }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { return true; }
        }
        return false;
    }
};