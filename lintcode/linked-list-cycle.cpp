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
			 *           * @return: True if it has a cycle, or false
			 *                */
			    bool hasCycle(ListNode *head) {
					if(head == NULL || head->next == NULL) return false;
					ListNode *slow = head;
					ListNode *fast = head->next;
					while(fast){
						if(slow == fast) return true;
						slow = slow->next;
						if(!fast->next) return false;
						fast = fast->next->next;
					}
					return false;
		       }
};
