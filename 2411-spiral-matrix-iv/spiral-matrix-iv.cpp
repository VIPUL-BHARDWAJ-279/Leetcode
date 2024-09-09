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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode * c=head;

        int top=0,bottom=m-1,left=0,right=n-1;

        while(top<=bottom && left<=right){

            for(int j=left;j<=right;j++){
                if(c){
                    ans[top][j]=c->val;
                    c=c->next;
                }
            }
            top++;


            for(int i=top;i<=bottom;i++){
                if(c){
                    ans[i][right]=c->val;
                    c=c->next;
                }
            }
            right--;


            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    if(c){
                        ans[bottom][j]=c->val;
                        c=c->next;
                    }
                }
            }
            bottom--;


            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    if(c){
                        ans[i][left]=c->val;
                        c=c->next;
                    }
                }
            }
            left++;
            
        }

        return ans;
    }
};