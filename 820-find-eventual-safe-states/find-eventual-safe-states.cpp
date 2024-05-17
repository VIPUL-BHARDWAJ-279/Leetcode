class Solution {
public:
    // DFS to check is there a cycle present when we start from the root node
    bool cycleNodesFrom(int  rootNode, vector<vector<int>> & adj, vector<bool> & vis, vector<bool> & pathVis, vector<bool> & cycleAtNode){
        vis[rootNode]=true;
        pathVis[rootNode]=true;
        
        for(auto it : adj[rootNode]){
            if(!vis[it]){
                if(cycleNodesFrom(it,adj,vis,pathVis,cycleAtNode))return cycleAtNode[rootNode]=true;
            }
            else if(pathVis[it])return cycleAtNode[rootNode]=true;
        }
        pathVis[rootNode]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n=adj.size();
        vector<bool> vis(n,false),pathVis(n,false),cycleAtNode(n,false);
        vector<bool>includeNode(n,true);

        for(int i=0;i<n;i++){
            if(!vis[i])cycleNodesFrom(i,adj,vis,pathVis,cycleAtNode);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)if(!cycleAtNode[i])ans.push_back(i);
        return ans;
    }
};