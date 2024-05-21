class Solution {
public:
    // Recursion with memoization
    // int solve(int sum,int k,int i,vector<vector<int>>& triangle,vector<vector<int>> & dp){
    //     if(k>=triangle.size())return 0;
    //     if(dp[k][i]!=INT_MIN)return dp[k][i];
    //     return dp[k][i]=triangle[k][i]+min(solve(sum,k+1,i,triangle,dp),solve(sum,k+1,i+1,triangle,dp));
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),INT_MIN));
    //     return solve(0,0,0,triangle,dp);
    // }

    //Tabulation
    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)dp[n-1][j]=triangle[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                int lower_left=dp[i+1][j];
                int lower_right=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(lower_left,lower_right);
            }
        }
        return dp[0][0];
    }
};