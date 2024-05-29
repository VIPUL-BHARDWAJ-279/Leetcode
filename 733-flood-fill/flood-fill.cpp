class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor==color)return image;
        
        int m=image.size(),n=image[0].size();
        vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            image[x][y]=color;
            for(auto [dx,dy]:directions){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==originalColor)q.push({nx,ny});
            }
        }
        return image;
    }
};