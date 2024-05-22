class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int n=arr.size();
        vector<bool> vis(n,false);
        queue<int> q;

        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            int ind1=ind+arr[ind],ind2=ind-arr[ind];
            if((ind1>=0&&ind1<n &&arr[ind1]==0) || (ind2>=0&&ind2<n && arr[ind2]==0))return true;
            if(ind1>=0&&ind1<n && !vis[ind1])vis[ind1]=true,q.push(ind1);
            if(ind2>=0&&ind2<n && !vis[ind2])vis[ind2]=true,q.push(ind2);
        }
        return false;
    }
};