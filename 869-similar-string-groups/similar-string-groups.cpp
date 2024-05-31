class Solution {
public:
    bool areSimilar(string & s, string & t){
        if(s.size()!=t.size())return false;
        int diff=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i])diff++;
            if(diff>2)return false;
        }
        return (diff<=2);
    }

    void dfs(int node, vector<bool> & vis, vector<vector<int>> & adj){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it,vis,adj);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(),groupCnt=0;
        vector<vector<int>> adj(n,vector<int>(0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(areSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                groupCnt++;
                dfs(i,vis,adj);
            }
        }
        return groupCnt;
    }
};