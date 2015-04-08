#include<iostream>
 
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode dummy(-1);
		int carry = 0;
		ListNode *prev = &dummy;
		ListNode *pa, *pb;
		for (pa = l1, pb = l2; pa != NULL || pb != NULL; pa = pa == NULL ? NULL : pa->next,
			pb = pb == NULL ? NULL : pb->next, prev = prev->next)
		{
			 const int ai = pa == NULL ? 0 : pa->val;
			 const int bi = pb == NULL ? 0 : pb->val;
			int value = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;
			prev->next = new ListNode(value);
		}
		if (carry > 0)
			prev->next = new ListNode(carry);
		return dummy.next;
	}
};

