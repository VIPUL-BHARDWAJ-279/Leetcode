class DisjointSet {
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }

    int find(int node){ // Find Ultimate Parent of Node
        if(node==parent[node])return node;
        return parent[node]=find(parent[node]);
    }

    void unionByRank(int x, int y){
        int parent_x=find(x), parent_y=find(y);
        if(parent_x == parent_y)return;

        if(rank[parent_x]>rank[parent_y])parent[parent_y]=parent_x;
        else if(rank[parent_x]<rank[parent_y])parent[parent_x]=parent_y;
        else{
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
    }

};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto & eqn:equations)if(eqn[1]=='=')ds.unionByRank(eqn[0]-'a',eqn[3]-'a');
        for(auto & eqn:equations)if(eqn[1]=='!')if(ds.find(eqn[0]-'a')==ds.find(eqn[3]-'a'))return false;
        return true;
    }
};