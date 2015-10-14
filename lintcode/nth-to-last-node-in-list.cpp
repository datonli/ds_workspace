/**
 *  * Definition of ListNode
 *   * class ListNode {
 *    * public:
 *     *     int val;
 *      *     ListNode *next;
 *       *     ListNode(int val) {
 *        *         this->val = val;
 *         *         this->next = NULL;
 *          *     }
 *           * }
 *            */
class Solution {
		public:
		    /**
			 *      * @param head: The first node of linked list.
			 *           * @param n: An integer.
			 *                * @return: Nth to last node of a singly linked list. 
			 *                     */
			    ListNode *nthToLast(ListNode *head, int n) {
					ListNode *p = head;
					while(n--) p = p->next;
					while(p){
						p = p->next;
						head = head->next;
					}
					return head;
			    }
};

