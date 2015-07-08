#include "list_def.h"

class Solution {
	public:
		ListNode *listHead(){
			int val[] = {3,5,1,6,7,2};
			ListNode *head = new ListNode(val[0]);
			ListNode *pre = head,*cur;
			for(int i = 1; i < sizeof(val)/sizeof(val[0]); i ++)
			{
				cur = new ListNode(val[i]);
				pre->next = cur;
				pre = cur;	
			}	
			return head;
		}
		void printList(ListNode *head){
			while(head != NULL){
				cout << head->val << endl;
				head = head->next;
			}
		}
		    ListNode* reverseList(ListNode* head) {
			if(head == NULL || head->next == NULL)
				return head;
			ListNode* k = head,  *q = head->next->next;
			head = head->next;
			k->next = NULL;
			while(q != NULL)
			{
				head->next = k;
				k = head;
				head = q;
				q = q->next;
			}
			head->next = k;
			return head;
		    }
		    ListNode *reverseBetween(ListNode *head,int m,int n){
			if(head == NULL || head->next == NULL || m == n)
			{
				return head;
			}	
			ListNode *begin = head,*end = head;
			int start = m,len = n;
			while(--m > 1) 
				begin = begin->next ;
			while(--n) end = end->next;
			 if(len-start == 1 )
			{
			              begin->next = end->next;
			                end->next = begin;
			           if(nn == len && begin->next != NULL)
			           return begin->next;
			            return end;
			 }
			/*if(len-start == 1 )
			{
				begin->next = end->next;
				end->next = begin;
				return end;
			}*/
			ListNode *k = begin,*p = begin->next, *q  = begin->next->next;
			k->next = end;
			p->next = end->next;
			k = p;
			p = q;
			q = q->next;
			while(q != end->next)
			{
				p->next = k;
				k = p;
				p = q;
				q = q->next;				
			}
			p->next = k;
			if(start == 1 )
				return p;
			else
				return head;
		    }
		    ListNode* swapPairs(ListNode* head) {
			ListNode *first = head;
			ListNode *second ;
			ListNode *third;
			head = head->next;
			while(first != NULL && first->next != NULL)
			{
				second = first->next;
				third = second->next;
				second->next = first;
				first->next = third;
				first = third;
			}
			return head;
		    }
};


int main()
{
	Solution *sol = new Solution();
	ListNode *head = sol->listHead();
	sol->printList(head);
	head = sol->reverseList(head);
	sol->printList(head);
	//head = sol->reverseBetween(head,2,4);
	sol->printList(head);
	cout << "\n" << endl;
	sol->swapPairs(head);
	sol->printList(head);
	return 0;
}
