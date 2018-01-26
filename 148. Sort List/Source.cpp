#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head && head->next) {
            ListNode *fast = head, *slow = head;
            while (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            ListNode *head_ = slow->next;
            slow->next = nullptr;
            head = sortList(head);
            head_ = sortList(head_);
            head = mergeSortedList(head, head_);
        }
        return head;
    }
    ListNode *mergeSortedList(ListNode *head1, ListNode *head2) {
        ListNode *head, *tail;
        if (head1->val <= head2->val) {
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }
        tail = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
        if (head1) {
            tail->next = head1;
        } else if (head2) {
            tail->next = head2;
        }
        return head;
    }
};
