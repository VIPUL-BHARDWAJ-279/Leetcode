class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j,int & area, vector<vector<bool>> & vis, vector<vector<int>> & grid){
        vis[i][j]=true;
        area++;
        for(auto [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1 && !vis[nx][ny])dfs(nx,ny,area,vis,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area=0;
                    dfs(i,j,area,vis,grid);
                    maxi=max(maxi,area);
                }
            }
        }
        return maxi;
    }
};