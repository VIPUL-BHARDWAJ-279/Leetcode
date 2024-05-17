class Solution {
public:
    void dfs(int rootNode, vector<vector<int>> & graph, vector<bool> & vis){
        vis[rootNode]=true;
        for(int i=0;i<graph[rootNode].size();i++)if(graph[rootNode][i]==1 && vis[i]==false)dfs(i,graph,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n=isConnected.size(),provinceCnt=0;
        vector<bool> vis(n,false);
        queue<int> q;
        for(int node=0;node<n;node++){
            if(vis[node]==false){
                provinceCnt++;
                dfs(node,isConnected,vis);
            }
        }
        return provinceCnt;
    }
};