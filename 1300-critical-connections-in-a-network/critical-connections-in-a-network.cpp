class Solution {
public:
    // Tarjan's dfs algo to find bridges (critical edges) in a graph;
    void tarjanDfs(int node, int parent ,vector<bool> & vis, vector<vector<int>> & adj, int & timer, vector<int> & insertTime,  vector<int> & minInsertTime, vector<vector<int>> & bridges){
        vis[node]=true;
        insertTime[node]=minInsertTime[node]=timer;

        timer++;

        for(auto child:adj[node]){
            if(child==parent)continue;
            if(vis[child]==false){
                tarjanDfs(child,node,vis,adj,timer,insertTime,minInsertTime,bridges);
                minInsertTime[node]=min(minInsertTime[node],minInsertTime[child]);
                if(minInsertTime[child]>insertTime[node]){ //Its a bridge
                    bridges.push_back({node,child});
                }
            }
            else minInsertTime[node]=min(minInsertTime[node],minInsertTime[child]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>> adj(n),bridges;
        for(auto edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> insertTime(n),minInsertTime(n);
        vector<bool> vis(n,false);
        int timer=1;
        tarjanDfs(0,-1,vis,adj,timer,insertTime,minInsertTime,bridges);
        return bridges;
        
    }
};