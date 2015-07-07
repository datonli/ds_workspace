class Solution {
	public:
		    ListNode* reverseList(ListNode* head) {
			if(head == NULL || head->next == NULL)
				return head;

			ListNode* k = head,  *q = head->next->next;
			head = head->next;
			while(q != NULL)
			{
				head->next = k;
				k = head;
				head = q;
				q = q->next;
			}
			head->next = k;
			return head;
};
