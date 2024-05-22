class Solution {
public:
    bool inBoundary(int &i,int &j,int &m, int &n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0)),directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    for(auto dir:directions){
                        int nx=i+dir[0],ny=j+dir[1];
                        if(inBoundary(nx,ny,m,n) && mat[nx][ny]==0){
                            q.push({i,j});
                            vis[i][j]=true;
                            break;
                        }
                    }
                }
                else vis[i][j]=true;

            }
        }
        int level=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(auto dir:directions){
                    int nx=x+dir[0],ny=y+dir[1];
                    if(inBoundary(nx,ny,m,n) && mat[nx][ny]>0 && !vis[nx][ny]){
                        mat[nx][ny]=level+2;
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
        return mat;
    }
};