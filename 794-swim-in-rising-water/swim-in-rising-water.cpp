class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};

        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            int minTime=pq.top()[0],x=pq.top()[1],y=pq.top()[2]; pq.pop();

            if(x==n-1 && y==n-1)return minTime;
            for(auto [dx,dy]:directions){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(!vis[nx][ny]){
                        vis[nx][ny]=true;
                        pq.push({max(minTime,grid[nx][ny]),nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};