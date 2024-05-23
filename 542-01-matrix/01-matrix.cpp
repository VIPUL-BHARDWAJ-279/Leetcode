class Solution {
public:
    bool inBoundary(int &i,int &j,int &m, int &n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                auto [x,y]=q.front();q.pop();
                for(auto [dirX,dirY]:directions){
                    int nx=x+dirX, ny=y+dirY;
                    if(inBoundary(nx,ny,m,n) && mat[nx][ny]==1 && !vis[nx][ny]){
                        ans[nx][ny]=level+1;
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
        return ans;
    }
};