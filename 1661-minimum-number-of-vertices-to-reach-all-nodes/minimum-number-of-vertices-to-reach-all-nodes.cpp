class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);

        vector<bool>isReachable(n,false);
        vector<int> ans;

        for(int i=0;i<edges.size();i++)isReachable[edges[i][1]]=true;
        for(int i=0;i<isReachable.size();i++)if(isReachable[i]==false)ans.push_back(i);
        return ans;
    }
};