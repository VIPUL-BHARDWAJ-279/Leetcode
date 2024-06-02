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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        
        ListNode *c1=l1, *c2=l2, *end1;
        int len1=0,len2=0;

        while(c1->next)len1++,c1=c1->next;
        end1=c1;
        len1++;
        while(c2)len2++,c2=c2->next;

        if(len1<len2)return addTwoNumbers(l2,l1);

        c1=l1;c2=l2;
        
        int sum,digit,carry=0;

        while(c1 && c2){
            sum=(c1->val+c2->val+carry);
            digit=sum%10;
            carry=sum/10;
            c1->val=digit;
            c1=c1->next;
            c2=c2->next;
        }
        while(c1){
            sum=(c1->val+carry);
            digit=sum%10;
            carry=sum/10;
            c1->val=digit;
            c1=c1->next;
        } 
        if(carry==1)end1->next=new ListNode(1);
        return l1;
    }
};

