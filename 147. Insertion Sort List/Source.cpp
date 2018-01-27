#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *tail = head;
        while (tail->next) {
            ListNode *temp = preHead, *cur = tail->next;
            while (temp->next != cur && temp->next->val < cur->val) {
                temp = temp->next;
            }
            tail->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            tail = tail->next;
        }
        return head;
    }
};
