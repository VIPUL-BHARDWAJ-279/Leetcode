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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto num:nums)mp[num]++;
        vector<int> v;
        while(head!=NULL){
            if(mp[head->val]==0)v.push_back(head->val);
            head=head->next;
        }

        ListNode * newHead=new ListNode(v[0]);
        ListNode * curr=newHead;
        for(int i=1;i<v.size();i++){

            ListNode * node=new ListNode(v[i]);
            curr->next=node;
            curr=node;

        }
        return newHead;

    }
};