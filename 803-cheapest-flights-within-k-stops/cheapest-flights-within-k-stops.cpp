class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto & edge:flights){
            int u=edge[0], v=edge[1], wt=edge[2];
            adj[u].push_back({v,wt});
        }

        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);

        dist[src]=0;
        q.push({src,0});

        int steps=0;

        while(!q.empty() && steps<=k){
            int siz=q.size();
            while(siz--){
                int u=q.front().first, d=q.front().second; q.pop();

                for(auto & pairy:adj[u]){
                    int v=pairy.first;
                    int wt=pairy.second;

                    if(d+wt<dist[v]){
                        dist[v]=d+wt;
                        q.push({v,d+wt});
                    }
                }
            }
            steps++;
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};