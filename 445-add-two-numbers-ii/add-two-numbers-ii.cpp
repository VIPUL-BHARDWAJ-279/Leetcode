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
    void addPlease(int & carry, ListNode* l1, ListNode* l2){
        if(!l1 || !l2)return;

        addPlease(carry,l1->next,l2->next);

        int sum=l1->val+l2->val+carry;
        int digit=sum%10;
        carry=sum/10;
        l1->val=digit;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1,*h2=l2;
        int n1=0,n2=0;
        while(h1){
            h1=h1->next;
            n1++;
        }
        while(h2){
            h2=h2->next;
            n2++;
        }
        if(n1<n2)return addTwoNumbers(l2,l1);
        int diff=n1-n2;
        while(diff--){
            ListNode * x=new ListNode(0);
            x->next=l2;
            l2=x;
        } 
        int carry=0;
        addPlease(carry,l1,l2);
        if(carry>0){
            ListNode * x=new ListNode(carry);
            x->next=l1;
            l1=x;
        }
        return l1;
    }
};