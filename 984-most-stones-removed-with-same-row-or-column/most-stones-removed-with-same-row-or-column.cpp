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
        int parent_x=findPar(x), parent_y=findPar(y);
        if(parent_x == parent_y)return;

        if(rank[parent_x]>rank[parent_y])parent[parent_y]=parent_x;
        else if(rank[parent_x]<rank[parent_y])parent[parent_x]=parent_y;
        else parent[parent_y]=parent_x, rank[parent_x]++;
    }

    void uniteBySize(int x, int y){
        int parent_x=findPar(x), parent_y=findPar(y);
        if(parent_x == parent_y)return;

        if(size[parent_x]>size[parent_y])parent[parent_y]=parent_x, size[parent_x]+=size[parent_y];
        else if(size[parent_x]<size[parent_y])parent[parent_x]=parent_y, size[parent_y]+=size[parent_x];
        else parent[parent_y]=parent_x , size[parent_x]+=size[parent_y];
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