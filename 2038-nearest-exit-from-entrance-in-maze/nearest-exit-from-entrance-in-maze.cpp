class Solution {
public:
    vector<vector<int>> direction={{1,0},{0,1},{-1,0},{0,-1}};
    bool isBoundaryPoint(int i,int j, int m, int n){
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
    bool isEntrance(int i, int j, vector<int> & root){
        if(i==root[0] && j==root[1])return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& root) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int m=maze.size(),n=maze[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<vector<int>> q;
        int steps=0;
        vis[root[0]][root[1]]=true;
        q.push({root[0],root[1],steps});
        while(!q.empty()){
            int i=q.front()[0],j=q.front()[1];
            steps=q.front()[2];
            q.pop();
            if(isBoundaryPoint(i,j,m,n) && !isEntrance(i,j,root))return steps;

            for(int k=0;k<4;k++){
                int newi=i+direction[k][0];
                int newj=j+direction[k][1];
                if( newi>=0 && newi<m && newj>=0 && newj<n && vis[newi][newj]==false){
                    if(maze[newi][newj]=='.'){
                        vis[newi][newj]=true;
                        q.push({newi,newj,steps+1});
                    }
                }
            }
        }

        return -1;

    }
};