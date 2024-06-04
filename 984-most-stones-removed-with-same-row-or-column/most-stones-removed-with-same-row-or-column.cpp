class DisjointSet {
    vector<int> parent,rank,size;
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size(),components=0;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]  ||  stones[i][1]==stones[j][1])ds.uniteByRank(i,j);
            }
        }
        for(int i=0;i<n;i++)if(ds.findPar(i)==i)components++;
        return n-components;
    }
};