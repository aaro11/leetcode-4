
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
    istNode *partition(ListNode *head, int x) 
    {
		if (head == NULL)
        {
            return NULL;
        }

		ListNode tmp(~0);
		tmp.next = head;

		ListNode *p = &tmp;       
        
        //然后从这里开始查找节点
        // 如果小于 x 插到p的后面
        // p指针向后移动
        
        ListNode *pre_q = p;
        ListNode *q = p->next;
        ListNode *after_q = NULL;
        
        while(q)
        {
			
            after_q = q->next;
            if(q->val < x)
            {

				if (q == p->next)
				{
					p = p->next;
					q = q->next;

					pre_q = pre_q->next;
					continue;
				}
				else
				{
					q->next = p->next;
					p->next = q;
					p = p->next;

					//连接前后节点
					pre_q->next = after_q;
					q = after_q;
				}
				         
            }
            else
            {
                pre_q = pre_q->next;
                q = q->next;
            }
        }        
		return tmp.next;
    }
};

int main()
{
	ListNode a1(1);
	ListNode a2(3);
	ListNode a3(2);

	a1.next = &a2;
	a2.next = &a3;
	
	Solution s;

	ListNode *p = s.partition(&a1, 3);

    return 0;
}