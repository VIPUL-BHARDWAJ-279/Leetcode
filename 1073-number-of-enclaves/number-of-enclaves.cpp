class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    bool onBoundary(int i, int j, int & m, int & n){
        return (i==0 || j==0 || i==m-1 || j==n-1);
    }
    bool inBoundary(int & i, int & j, int & m, int & n){
        return (i>=0 && j>=0 && i<=m-1 && j<=n-1);
    }
    void dfs(int i,int j,int & m,int & n, vector<vector<bool>> & vis ,vector<vector<int>> & grid){
        vis[i][j]=true;
        for(auto & [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if(inBoundary(nx,ny,m,n) && grid[nx][ny]==1 && !vis[nx][ny])dfs(nx,ny,m,n,vis,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            if(onBoundary(i,0,m,n) && grid[i][0]==1 && !vis[i][0])dfs(i,0,m,n,vis,grid);
            if(onBoundary(i,n-1,m,n) && grid[i][n-1]==1 && !vis[i][n-1])dfs(i,n-1,m,n,vis,grid);   
        }
        for(int j=0;j<n;j++){
            if(onBoundary(0,j,m,n) && grid[0][j]==1 && !vis[0][j])dfs(0,j,m,n,vis,grid);
            if(onBoundary(m-1,j,m,n) && grid[m-1][j]==1 && !vis[m-1][j])dfs(m-1,j,m,n,vis,grid);
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]==1 && !vis[i][j])ans++;
        return ans;
    }
};