class Solution {
public:
int n;
    void dfs(int rootNode, vector<vector<int>> & graph, vector<bool> & vis){
        vis[rootNode]=true;
        for(int i=0;i<n;i++)if(graph[rootNode][i]==1 && vis[i]==false)dfs(i,graph,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        n=isConnected.size();
        int provinceCnt=0;
        vector<bool> vis(n,false);
        
        for(int node=0;node<n;node++){
            if(vis[node]==false){
                provinceCnt++;
                dfs(node,isConnected,vis);
            }
        }
        return provinceCnt;
    }
};