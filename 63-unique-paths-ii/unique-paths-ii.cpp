// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& badGrid) {
//         int m=badGrid.size(),n=badGrid[0].size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//         dp[0][1]=1;
//         for(int i=1;i<m+1;i++){
//             for(int j=1;j<n+1;j++){
//                 if(badGrid[i-1][j-1]==0)dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m][n];
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& badGrid) {
        int m=badGrid.size(),n=badGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(badGrid[i][j]==1)dp[i][j]=0;
                else{
                    if(i==0 && j==0)dp[i][j]=1;
                    else if(i==0 && j>0)dp[i][j]=dp[i][j-1];
                    else if(i>0 && j==0)dp[i][j]=dp[i-1][j];
                    else if(i>0 && j>0)dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};