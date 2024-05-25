class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<bool>> & vis , vector<vector<int>> & grid){
        vis[i][j]=true;
        for(auto & [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1 && !vis[nx][ny])dfs(nx,ny,vis,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(i,0,vis,grid);
            if(grid[i][n-1]==1)dfs(i,n-1,vis,grid);   
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)dfs(0,j,vis,grid);
            if(grid[m-1][j]==1)dfs(m-1,j,vis,grid);
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]==1 && !vis[i][j])ans++;
        return ans;
    }
};