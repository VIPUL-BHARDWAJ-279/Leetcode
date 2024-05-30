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

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                
                if(mp.find(mail)!=mp.end())ds.unionByRank(i,mp[mail]);
                else mp[mail]=i;
            }
        }

        vector<string> mergedMails[n];

        for(auto x:mp){
            string mail=x.first;
            int node=ds.find(x.second);
            mergedMails[node].push_back(mail); // Key point --> we are pushing mails in ultimate parent of their corresponding nodes
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergedMails[i].size()==0)continue;
            
            sort(mergedMails[i].begin(),mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto mail:mergedMails[i])temp.push_back(mail);

            ans.push_back(temp);
        }
        return ans;

    }
};