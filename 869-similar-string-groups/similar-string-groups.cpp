class Solution {
public:
    bool areSimilar(string & s, string & t){
        if(s.size()!=t.size())return false;
        char a='?',b=';',x='!',y='>';
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                if(cnt>2)return false;
                cnt++;
                if(cnt==1)a=s[i],b=t[i];
                if(cnt==2)x=s[i],y=t[i];
            }
        }
        if(cnt==0 || ( cnt==2 && a==y && b==x))return true;
        return false;
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