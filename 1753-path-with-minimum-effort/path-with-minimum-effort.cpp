class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        set<vector<int>> seti;
        vector<vector<int>> effort(n,vector<int>(m,1e7));

        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

        seti.insert({0,0,0});  // {x,y,currEffort calculated from initial point to x,y}
        effort[0][0]=0;

        while(!seti.empty()){
            vector<int> curr = *(seti.begin());     
            seti.erase(curr);

            int x=curr[0], y=curr[1], maxEffortTillNow=curr[2];
            if(x==n-1 && y==m-1)return maxEffortTillNow;
            
            for(auto [dx,dy]:directions){
                int nx=x+dx, ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newEffort=max(maxEffortTillNow,abs(heights[nx][ny]-heights[x][y]));
                    if(newEffort < effort[nx][ny]){
                        // if(effort[nx][ny] != 1e7)seti.erase({nx,ny,effort[nx][ny]});

                        effort[nx][ny]=newEffort;
                        seti.insert({nx,ny,newEffort});
                    }
                }
            }
        }
        return -1;
    }
};