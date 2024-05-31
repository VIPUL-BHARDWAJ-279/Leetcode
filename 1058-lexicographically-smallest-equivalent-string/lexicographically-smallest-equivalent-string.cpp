class DisjointSet {
    vector<int> parent,rank,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);

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
        else parent[parent_y]=parent_x, rank[parent_x]++;
    }

    void unionBySize(int x, int y){
        int parent_x=find(x), parent_y=find(y);
        if(parent_x == parent_y)return;

        if(size[parent_x]>size[parent_y])parent[parent_y]=parent_x, size[parent_x]+=size[parent_y];
        else if(size[parent_x]<size[parent_y])parent[parent_x]=parent_y, size[parent_y]+=size[parent_x];
        else parent[parent_y]=parent_x , size[parent_x]+=size[parent_y];
    }

    void unionBySmallestNumber(int x, int y){
        int parent_x=find(x), parent_y=find(y);
        if(parent_x == parent_y)return;

        if(parent_x < parent_y)parent[parent_y]=parent_x;
        else if(parent_x > parent_y)parent[parent_x]=parent_y;
        
    }

};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i=0;i<s1.size();i++){
            ds.unionBySmallestNumber(min(s1[i]-'a',s2[i]-'a'),max(s1[i]-'a',s2[i]-'a'));
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            ans+=ds.find(baseStr[i]-'a')+'a';
        }
        return ans;
    }
};