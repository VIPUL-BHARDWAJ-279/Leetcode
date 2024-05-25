class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
    bool inBoundary(int & i, int & j, int & m, int & n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    bool isLowerCase(char & ch){
        return (ch>='a' && ch<='z');
    }
    bool isUpperCase(char & ch){
        return (ch>='A' && ch<='Z');
    }
    int shortestPathAllKeys(vector<string>& grid) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>> q;

        int level=0,keys=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@')q.push({i,j,0});
                else if(isLowerCase(grid[i][j]))keys++;
            }
        }

        int final_key_status_in_decimal=pow(2,keys)-1; 
        bool vis[m][n][final_key_status_in_decimal+1];
        memset(vis,0,sizeof(vis));
        vis[q.front()[0]][q.front()[1]][0]=true;


        while(!q.empty()){
            int siz=q.size();
            while(siz--){

                int x=q.front()[0],y=q.front()[1],key_status=q.front()[2];q.pop(); 

                if(key_status == final_key_status_in_decimal)return level;

                for(auto [dx,dy]:directions){
                    int nx=x+dx, ny=y+dy;
                    if(inBoundary(nx,ny,m,n) && grid[nx][ny]!='#'){
                        char ch=grid[nx][ny];
                        if(isLowerCase(ch)){ // key
                            int new_key_status = key_status | 1<<(ch-'a');  // calculate new key status by adding the new key to the previous status
                            if(vis[nx][ny][new_key_status]==0){    // if the cell is not visited using the new key status                     
                                vis[nx][ny][new_key_status]=1;
                                q.push({nx,ny,new_key_status});
                            }
                        }
                        else if(isUpperCase(ch)){  // lock
                            if(vis[nx][ny][key_status]==0 && (key_status>>(ch-'A') & 1)==1){ // not visited & have the key to this lock
                                vis[nx][ny][key_status]=1;
                                q.push({nx,ny,key_status});
                            }
                        }
                        else { // empty cell
                            if(vis[nx][ny][key_status]==0){
                                vis[nx][ny][key_status]=1;
                                q.push({nx,ny,key_status});
                            }
                        }
                    }

                }
            }
            level++;
        }
        return -1;
    }
};