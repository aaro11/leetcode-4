
#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode * insertNode(ListNode *insert, ListNode *head, ListNode *tail, bool &res)
	{
		if ((insert == NULL) ||
			(head == NULL))
		{
			res = false;
			return head;
		}		

		//如果是插入的值比链表头还小 插入到头部
		if (insert->val < head->val)
		{
			insert->next = head;
			res = true;
			return insert;
		}

		ListNode *p = head;
		ListNode *q = p->next;

		while (p != tail)
		{
			if (insert->val < q->val)
			{
				//插入到q的前面
				p->next = insert;
				insert->next = q;
				res = true;
				return head;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		res = false;
		return head;
	}

    ListNode *insertionSortList(ListNode *head) 
    {
		if ((head == NULL) || (head->next == NULL))
		{
			return head;
		}

		ListNode *p = head;
		ListNode *q = p->next;
		

		ListNode *pre_q = p;
		ListNode *after_q = q->next;

		bool inserRes = false;
		ListNode *h = head;



		// 插入排序
		// 已经排序好了的节点
		// head 到 p;每次比较的范围
		// 每次循环的范围 是从p->next 到链表尾
		while (q)
		{
			after_q = q->next;

			h = insertNode(q, h, p, inserRes);

			if (inserRes)
			{
				// 先链接前后节点
				pre_q->next = after_q;
				//如果插入进去了 不要再往后面遍历了
				// 重新把q放置到p的后面 再循环
				q = p->next;
				pre_q = p;				
			}
			else
			{
				pre_q = pre_q->next;
				q = q->next;
			}
		}
		return h;
    }
};

int main()
{
	ListNode a1(7);
	/*ListNode a2(3);
	ListNode a3(5);
	ListNode a4(2);
	ListNode a5(9);
	ListNode a6(11);
	ListNode a7(6);*/

	/*a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;*/

	Solution s;

	ListNode *p = s.insertionSortList(&a1);

	return 0;
}