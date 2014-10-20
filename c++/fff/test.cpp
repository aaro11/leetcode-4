
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define NULL 0
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x=0) : label(x), next(NULL), random(NULL) {}
};





//Given a singly linked list L : L0��L1������Ln - 1��Ln,
//reorder it to : L0��Ln��L1��Ln - 1��L2��Ln - 2����

//���赥������ܳ���ΪL��ͷ��㵽����ڵľ���Ϊa������ڵ�����ָ�������Ľ�����Ϊx�����ĳ���Ϊr����ָ���ܹ�����s�������ָ������2s�������⣬��ָ��Ҫ׷����ָ��Ļ���ָ������Ҫ�ڻ�����ת��һȦ��(����ת��nȦ��x�ľ���)���õ����¹�ϵ��
//s = a + x;
//2s = a + nr + x;
//= >a + x = nr;
//= >a = nr - x;
//����ʽ��֪������ͷ�����������ֱ���һָ�룬ͬ��(����)ǰ���������һ�������ڻ���ڽ�㣬��࣡

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *meetNode = findMeetNode(head);
		ListNode *tmp = head;
		//a = nr - x;
		while (meetNode)
		{
			if (meetNode == tmp)
			{
				return tmp;
			}
			tmp = tmp->next;
			meetNode = meetNode->next;
		}		
		return NULL;

	}
	//�õ��������
	ListNode *findMeetNode(ListNode *head)
	{
		if (head == head->next)
		{
			return head;
		}
		ListNode *p = head;
		ListNode *q = head;
		while ((p != NULL) || (q != NULL))
		{
			p = p->next;
			if ((q == NULL) || (q->next == NULL))
			{
				return NULL;
			}
			q = q->next->next;
			if (p == q)
			{
				return p;
			}
		}
		return NULL;
	}

	bool hasCycle(ListNode *head) {
		if (head == NULL)
		{
			return false;
		}
		if (head == head->next)
		{
			return true;
		}
		ListNode *p = head;
		ListNode *q = head;
		while ((p != NULL) || (q != NULL))
		{
			p = p->next;
			if ((q == NULL) || (q->next == NULL))
			{
				return false;
			}
			q = q->next->next;
			if (p == q)
			{
				return true;
			}
		}
		return false;

	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {

	}


	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		return NULL;
	}

	int singleNumber(int A[], int n) {
		int ones = 0;
		int twos = 0;
		int not_threes = 0;
		


		for (size_t i = 0; i < n; i++)
		{
			twos |= ones & A[i];
			ones ^= A[i];
			not_threes = ~(ones & twos);
			ones &= not_threes;
			twos &= not_threes;
		}
		return twos;
	}

	/*int singleNumber(int A[], int n) {
		int ones = 0;
		for (size_t i = 0; i < n; i++)
		{		
			ones ^= A[i];
		}
		return ones;
	}*/

};

int main1()
{
	ListNode a(0);
	ListNode b(1);
	/*ListNode c(2);
	ListNode d(3);
	ListNode e(4);
	ListNode f(5);*/

	a.next = &b;
	b.next = &a;
	/*b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &c;
*/
	Solution s;
	//ListNode *tmp = s.detectCycle(&a);

	//bool tmp = s.hasCycle(&a);

	int data[] = {1,1,1,22,22,22,55,55,55,1,1};
	s.singleNumber(data, sizeof(data));

	return 0;
}