class Solution {
public:
    void dfs(int root, int & ans,vector<bool> & vis, vector<vector<pair<int,bool>>> & adj){
        vis[root]=true;

        for(auto it:adj[root]){
            int neighbor=it.first;
            bool edge=it.second;
            if(!vis[neighbor]){
                if(edge==true)ans++;
                dfs(neighbor,ans,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        vector<vector<pair<int,bool>>> adj(n);
        vector<bool> vis(n,false);
        int ans=0;
        for(auto & x:connections){
            adj[x[0]].push_back({x[1],true});
            adj[x[1]].push_back({x[0],false});
        }
        dfs(0,ans,vis,adj);
        return ans;
    }
};