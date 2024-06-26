class Solution {
public:
    void dfs(int root, vector<bool> & vis, vector<vector<int>> & adj, vector<int> temp, vector<vector<int>> & ans){
        if(root==adj.size()-1){
            temp.push_back(root);
            ans.push_back(temp);
            return;
        }
        vis[root]=true;
        temp.push_back(root);
        for(auto it:adj[root]){
            if(!vis[it])dfs(it,vis,adj,temp,ans);
        }
        temp.pop_back();
        vis[root]=false; 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> ans;
        vector<bool> vis(adj.size(),false);
        vector<int> temp;
        // temp.push_back(0);
        dfs(0,vis,adj,temp,ans);
        return ans;
    }
};