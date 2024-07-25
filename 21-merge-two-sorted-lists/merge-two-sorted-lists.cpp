/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     // if list1 happen to be NULL
	// 	// we will simply return list2.
	// 	if(l1 == NULL)return l2;
		
	// 	// if list2 happen to be NULL
	// 	// we will simply return list1.
	// 	if(l2 == NULL)return l1;
		
	// 	// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
	// 	// we wall call recursively l1 -> next and whole l2 list.
	// 	if(l1 -> val <= l2 -> val){
	// 		l1 -> next = mergeTwoLists(l1 -> next, l2);
	// 		return l1;
	// 	}
	// 	// we will call recursive l1 whole list and l2 -> next
	// 	else{
	// 		l2 -> next = mergeTwoLists(l1, l2 -> next);
	// 		return l2;
    //     }  
    // }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
            ListNode* dummy=new ListNode();
            ListNode* curr=dummy, *i=l1, *j=l2;

            while(i && j){
                if(i->val<j->val){
                    curr->next=i;
                    i=i->next;
                    curr=curr->next;
                }
                else{
                    curr->next=j;
                    j=j->next;
                    curr=curr->next;
                }
            }
            if(i){  // we used 'if' in place of 'while' as the remaining list is already connected
                curr->next=i;
                i=i->next;
                curr=curr->next;
            }

            if(j){
                curr->next=j;
                j=j->next;
                curr=curr->next;
            }

            return dummy->next;
        }

    
};