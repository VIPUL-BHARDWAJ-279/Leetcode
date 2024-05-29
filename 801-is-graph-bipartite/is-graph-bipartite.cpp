class Solution {
private:
    bool checkBipartite(int start, vector<vector<int>> & adj, vector<int> & colorOf){
        int n=adj.size();
        queue<int> q;

        q.push(start);
        colorOf[start]=0;

        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adj[node]){
                if(colorOf[it]==-1){
                    colorOf[it] = !colorOf[node];
                    q.push(it);
                }
                else if(colorOf[it]==colorOf[node])return false;
            }
        }
        return true;
    
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> colorOf(n,-1);

        for(int i=0;i<n;i++){
            if(colorOf[i]==-1){
                if(checkBipartite(i,adj,colorOf)==false)return false;
            }
        }
        return true;
    }
        
};