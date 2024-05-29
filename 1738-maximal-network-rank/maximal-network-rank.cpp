class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adjMat(n,vector<int>(n,0));
        vector<int> indegrees(n,0);
        int ans=0;
        
        for(auto road:roads){
            indegrees[road[0]]++;
            indegrees[road[1]]++;

            adjMat[road[0]][road[1]]=1;
            adjMat[road[1]][road[0]]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,indegrees[i]+indegrees[j]-adjMat[i][j]);
            }
        }
        
        return ans;
    }
};