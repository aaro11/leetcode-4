

#include <iostream>
#include <vector>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) 
	{
		if (head == NULL)
		{
			return head;
		}
		vector<int> key;
		int size = 0;

		key.push_back(head->val);

		ListNode *p = head;
		ListNode *q = p->next;
		while (q)
		{
			size = key.size();
			for (size_t i = 0; i < size; i++)
			{
				//如果相等删除q
				if (key[i] == q->val)
				{
					p->next = q->next;
					q = p->next;
					goto lable;
				}
			}
			key.push_back(q->val);
			q = q->next;
			p = p->next;
		lable:
			;
		}

		return head;
	}

	
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}

		//需要返回的指针
		ListNode *res = NULL;
		if (l1->val < l2->val)
		{
			res = l1;
			l1 = l1->next;
		}
		else
		{
			res = l2;
			l2 = l2->next;
		}
		
		ListNode *p_res = res;		
		while (l1 || l2)
		{
			if (l1 == NULL)
			{
				p_res->next = l2;
				break;
			}

			if (l2 == NULL)
			{
				p_res->next = l1;
				break;
			}

			if (l1->val < l2->val)
			{
				p_res->next = l1;
				l1 = l1->next;
			}
			else
			{
				p_res->next = l2;
				l2 = l2->next;
			}

			p_res = p_res->next;
		}

		return res;
	}
};

int main()
{
	ListNode a1(1);
	ListNode a2(3);
	ListNode a3(5);
	ListNode a4(7);
	ListNode a5(9);
	ListNode a6(11);
	ListNode a7(12);

	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;

	ListNode b1(1);
	ListNode b2(2);
	ListNode b3(4);
	ListNode b4(6);
	ListNode b5(8);

	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;
	b4.next = &b5;

	Solution s;
	//s.deleteDuplicates(&a1);

	s.mergeTwoLists(&a1, &b1);
	return 0;
}