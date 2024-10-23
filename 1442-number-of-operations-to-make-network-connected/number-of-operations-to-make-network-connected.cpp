class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;


        vector<vector<int>> adj(n);
        vector<bool>vis(n,false);
        int components=0;


        for(auto &connection:connections){
            int u=connection[0],v=connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        function<void(int)> dfs=[&](int i){
            vis[i]=true;
            for(auto v:adj[i])if(!vis[v])dfs(v);
        };

        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                components++;
                dfs(i);
            }
        }

        return components-1;
    }
};