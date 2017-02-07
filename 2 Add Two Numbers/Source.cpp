#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#define nxt(x) ((x) == NULL ? x : x->next)
#define get(x) ((x) == NULL ? 0 : x->val)
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans = new ListNode(get(l1) + get(l2));
		int carry;
		ListNode *p = ans;
		if (ans->val >= 10) {
			carry = 1;
			ans->val %= 10;
		}
		else {
			carry = 0;
		}
		l1 = nxt(l1);
		l2 = nxt(l2);
		while (l1 != NULL || l2 != NULL || carry != 0) {
			int ans_t = get(l1) + get(l2) + carry;
			if (ans_t >= 10) {
				carry = 1;
				ans_t %= 10;
			}
			else { carry = 0; }
			p->next = new ListNode(ans_t);
			p = p->next;
			l1 = nxt(l1);
			l2 = nxt(l2);
		}
		return ans;
	}
};