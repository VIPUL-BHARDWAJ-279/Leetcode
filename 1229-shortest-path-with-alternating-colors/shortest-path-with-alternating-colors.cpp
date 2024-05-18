class Solution {
public:
    // void bfs(bool & color,vector<int> & ans, vector<vector<pair<int,bool>>> & adj){
    //     int n=adj.size();
    //     vector<bool> vis(n,false);
    //     vis[0]=true;
    //     queue<pair<int,bool>> q;
    //     q.push({0,color});

    //     int cnt=0;
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         q.pop();
    //         cnt++;
    //         for(auto it:adj[node]){
    //             if(!vis[it.first] && it.second==color){
    //                 vis[it.first]=true;
    //                 ans[it.first]=min(ans[it.first],cnt);
    //                 q.push(it);
    //             }
    //         }
    //         color=!color;
    //     }
    // }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        vector<int> ans(n,-1);
        vector<vector<pair<int,bool>>> adj(n);
        for(auto x:redEdges)adj[x[0]].push_back({x[1],false});
        for(auto x:blueEdges)adj[x[0]].push_back({x[1],true});

        vector<vector<bool>>vis(n,vector<bool>(2));
        queue<vector<int>>q;
        
        ans[0]=0;
        vis[0]={true,true};
        q.push({0,0,-1}) ;// {Node , Step Count , Previous Edge Color}

        while(!q.empty()){
            auto node=q.front()[0],steps=q.front()[1],prevColor=q.front()[2];
            q.pop();

            for(auto & it:adj[node]){
                int neighbour=it.first;
                int color=it.second;
                
                if(vis[neighbour][color]==false && color!=prevColor){
                    vis[neighbour][color]=true;
                    q.push({neighbour,steps+1,color});
                    if(ans[neighbour]==-1)ans[neighbour]=steps+1;
                }
            }
        }
        return ans;
        // bool color=true;
        // bfs(color,ans,adj);
        // color=false;
        // bfs(color,ans,adj);
        // for(int i=0;i<n;i++)if(ans[i]==INT_MAX)ans[i]=-1;
        // return ans;
    }
};