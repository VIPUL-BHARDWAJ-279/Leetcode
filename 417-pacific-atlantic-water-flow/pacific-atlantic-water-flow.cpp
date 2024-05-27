class Solution {
public:
    int m,n;
    vector<vector<int>> ans;
    vector<vector<bool>> pacific,atlantic;
    queue<pair<int,int>> q;

    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    void bfs(int i,int j,vector<vector<bool>> & vis, vector<vector<int>> & height){
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            if(vis[x][y])continue;
            vis[x][y]=true;
            if(pacific[x][y] && atlantic[x][y])ans.push_back({x,y});
            for(auto [dx,dy]:directions){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]){
                    if(height[nx][ny]>=height[x][y])q.push({nx,ny}); // opposite to the direction of flow
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        m=height.size(),n=height[0].size();
        pacific=atlantic=vector<vector<bool>>(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            bfs(i,0,pacific,height);
            bfs(i,n-1,atlantic,height);
        }
        for(int j=0;j<n;j++){
            bfs(0,j,pacific,height);
            bfs(m-1,j,atlantic,height);
        }

        return ans;
    }
};