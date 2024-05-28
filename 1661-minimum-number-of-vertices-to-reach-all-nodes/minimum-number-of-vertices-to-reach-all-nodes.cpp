class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int maxi=0;
        for(int i=0;i<edges.size();i++){
            maxi=max(maxi,edges[i][0]);
            maxi=max(maxi,edges[i][1]);
        }
        vector<bool>isReachable(maxi+1,false);
        vector<int> ans;

        for(int i=0;i<edges.size();i++)isReachable[edges[i][1]]=true;
        for(int i=0;i<isReachable.size();i++)if(isReachable[i]==false)ans.push_back(i);
        return ans;
    }
};