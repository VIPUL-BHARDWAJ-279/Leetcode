class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};

    bool inBoundary(int i, int j, int m,int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(int i,int j, vector<vector<bool>> & vis, vector<vector<int>> & grid,queue<pair<int,int>> & q){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==true)return;
        vis[i][j]=true;
        q.push({i,j});
        for(auto & dir:directions){
            int ni=i+dir.first,nj=j+dir.second;
            dfs(ni,nj,vis,grid,q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q; //q stores all the nodes of island '1' so as to start multi-source dfs
        bool flagi=false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,vis,grid,q);
                    flagi=true;
                    break;
                }
            }
            if(flagi)break;
        }
        int steps=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int i=q.front().first,j=q.front().second;
                q.pop();
                for(auto & dir:directions){
                    int ni=i+dir.first,nj=j+dir.second;
                    if(inBoundary(ni,nj,m,n) && vis[ni][nj]==false){
                        if(grid[ni][nj]==0)vis[ni][nj]=true,q.push({ni,nj});
                        else if(grid[ni][nj]==1)return steps;
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
};