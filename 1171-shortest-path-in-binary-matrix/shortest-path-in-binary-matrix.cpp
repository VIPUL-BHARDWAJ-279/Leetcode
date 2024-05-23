class Solution {
public:
    bool inBoundary(int & i, int & j, int & m, int & n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        int level=0;
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};

        if(grid[0][0]==0){
            vis[0][0]=true;
            q.push({0,0});
        }

        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                auto [x,y]=q.front();q.pop();
                if(x==m-1 && y==n-1)return level+1;
                for(auto [dx,dy]:directions){
                    int nx=x+dx,ny=y+dy;
                    if(inBoundary(nx,ny,m,n) && grid[nx][ny]==0 && !vis[nx][ny]){
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }

                }
            }
            level++;

        }
        return -1;
    }
};