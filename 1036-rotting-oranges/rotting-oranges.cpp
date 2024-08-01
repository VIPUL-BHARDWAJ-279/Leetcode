class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        int level=0;
        bool haveFresh=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)haveFresh=true;
            }
        }
        if(!haveFresh)return 0;
        
        while(!q.empty()){
            int siz=q.size();
            level++;
            while(siz--){
                auto [x,y]=q.front();q.pop();
                
                for(auto [dx,dy]:directions){
                    int nx=x+dx,ny=y+dy;
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1)grid[nx][ny]=2,q.push({nx,ny});
                }
            }
        }

        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]==1)return -1;

        return level-1;
    }
};