class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<bool>> & vis , vector<vector<char>> & grid){
        vis[i][j]=true;
        for(auto & [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && !vis[nx][ny] && grid[nx][ny]=='O')dfs(nx,ny,vis,grid);
        }
    }
    void solve(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            if(grid[i][0]=='O')dfs(i,0,vis,grid);
            if(grid[i][n-1]=='O')dfs(i,n-1,vis,grid);   
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]=='O')dfs(0,j,vis,grid);
            if(grid[m-1][j]=='O')dfs(m-1,j,vis,grid);
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]=='O' && !vis[i][j])grid[i][j]='X';
    }

};