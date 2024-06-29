class Solution {
public:

    void dfs(int ancestor,int root,vector<vector<int>> & ans, vector<vector<int>> & adj){
        
        
        for(auto node:adj[root]){
            if(ans[node].empty() || ans[node].back()!=ancestor){
                ans[node].push_back(ancestor);
                dfs(ancestor,node,ans,adj);
            }         
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n),ans(n);
        for(auto & edge:edges)adj[edge[0]].push_back(edge[1]);
        for(int i=0;i<n;i++)dfs(i,i,ans,adj);
        return ans;
    }
};