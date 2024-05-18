class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        vector<vector<int>> adj(n+1);
        for(auto x:trust)adj[x[0]].push_back(x[1]);
        int cnt=0,ind=-1;
        for(int i=1;i<n+1;i++)if(adj[i].size()==0)cnt++,ind=i;
        if(cnt==1){
            int k=0;
            for(int i=1;i<n+1;i++){
                if(i!=ind){
                    for(int j=0;j<adj[i].size();j++){
                        if(adj[i][j]==ind){
                            k++;
                            break;
                        }   
                    }
                }
            }
            if(k==n-1)return ind;
            return -1;
        }
        return -1;
    }
};