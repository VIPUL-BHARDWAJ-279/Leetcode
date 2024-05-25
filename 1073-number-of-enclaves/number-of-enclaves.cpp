class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    bool onBoundary(int & i, int & j, int & m, int & n){
        return (i==0 || j==0 || i==m-1 || j==n-1);
    }
    bool inBoundary(int & i, int & j, int & m, int & n){
        return (i>=0 && j>=0 && i<=m-1 && j<=n-1);
    }
    void dfs(int i,int j,int & m,int & n, vector<vector<bool>> & vis ,vector<vector<int>> & grid){
        vis[i][j]=true;
        for(auto [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if( inBoundary(nx,ny,m,n) && grid[nx][ny]==1 && !vis[nx][ny])dfs(nx,ny,m,n,vis,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(onBoundary(i,j,m,n) && grid[i][j]==1 && !vis[i][j])dfs(i,j,m,n,vis,grid);
            }
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]==1 && !vis[i][j])ans++;
        return ans;
    }
};