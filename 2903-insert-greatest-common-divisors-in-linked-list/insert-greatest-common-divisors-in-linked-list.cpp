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

    int findGcd(int a,int b){
        if(b==0)return a;
        return findGcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * c=head;

        while(c && c->next){
            ListNode * n=c->next;
            ListNode * gcdNode=new ListNode(findGcd(c->val,n->val));
            c->next=gcdNode;
            gcdNode->next=n;
            c=n;
        }

        return head;
    }
};