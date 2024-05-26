class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, bool & isValidIsland, vector<vector<int>> & grid){
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)isValidIsland=false;
        for(auto & [dx,dy]:directions){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0)grid[nx][ny]=-1,dfs(nx,ny,isValidIsland,grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    bool isValidIsland=true;
                    dfs(i,j,isValidIsland,grid);
                    ans+=isValidIsland==true?1:0;
                }
            }
        }
        return ans;
    }
};