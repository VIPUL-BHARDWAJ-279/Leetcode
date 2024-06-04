class DisjointSet {
public:
    vector<int> parent,rank,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);

        parent.resize(n+1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }

    int findPar(int node){ // Find Ultimate Parent of Node
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }

    void uniteByRank(int x, int y){
        int par_x=findPar(x), par_y=findPar(y);
        if(par_x == par_y)return;

        if(rank[par_x]>rank[par_y])parent[par_y]=par_x;
        else if(rank[par_x]<rank[par_y])parent[par_x]=par_y;
        else parent[par_y]=par_x, rank[par_x]++;
    }

    void uniteBySize(int x, int y){
        int par_x=findPar(x), par_y=findPar(y);
        if(par_x == par_y)return;

        if(size[par_x]>size[par_y])parent[par_y]=par_x, size[par_x]+=size[par_y];
        else if(size[par_x]<size[par_y])parent[par_x]=par_y, size[par_y]+=size[par_x];
        else parent[par_y]=par_x , size[par_x]+=size[par_y];
    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid){
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        int maxSize=0;
        bool zerosPresent=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto [dx,dy]:directions){
                        int nx=i+dx,ny=j+dy;
                        if(nx>=0 && ny>=0 && nx<n && ny<n){
                            if(grid[nx][ny]==1)ds.uniteBySize(n*i+j, n*nx+ny);
                        }
                    }   
                }
                else zerosPresent=true;
            }
        }

        if(!zerosPresent)return n*n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>uniqueParents;
                    int currentIslandSize=1;
                    for(auto [dx,dy]:directions){
                        int nx=i+dx,ny=j+dy;
                        if(nx>=0 && ny>=0 && nx<n && ny<n){
                            if(grid[nx][ny]==1){
                                int parent=ds.findPar(n*nx+ny);
                                if(uniqueParents.find(parent)==uniqueParents.end()){
                                    uniqueParents.insert(parent);
                                    currentIslandSize+=ds.size[parent];
                                }
                            }
                        }
                        maxSize=max(maxSize,currentIslandSize);
                    }                  
                }
            }
        }


        return maxSize;
        
    }
};