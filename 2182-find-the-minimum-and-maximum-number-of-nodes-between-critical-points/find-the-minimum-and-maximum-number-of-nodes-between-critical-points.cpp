class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> inds;
        int ind = 0;
        ListNode* prev = NULL,*curr = head, *nxt = head->next;
        while(curr)
        {
            if(prev && nxt)
            {
                if((curr-> val > prev->val && curr->val > nxt->val) || curr-> val < prev->val && curr->val < nxt->val)
                {
                    inds.push_back(ind);
                }
            }
            prev = curr;
            curr = curr->next;
            if(!curr->next) break;
            nxt = curr->next;
            ind++;
        }
        int mxD = INT_MIN, mnD = INT_MAX;
        if(inds.size() < 2) return {-1,-1};
        mxD = abs(inds[0] - inds[inds.size()-1]);
        for(int i = 0; i<inds.size()-1; i++)
        {
            mnD = min(mnD,inds[i+1]-inds[i]);
        }
        return {abs(mnD),abs(mxD)};
    }
};