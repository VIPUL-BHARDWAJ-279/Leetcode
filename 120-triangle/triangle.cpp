class Solution {
public:
    int solve(int sum,int k,int i,vector<vector<int>>& triangle,vector<vector<int>> & dp){
        if(k>=triangle.size())return 0;
        if(dp[k][i]!=INT_MIN)return dp[k][i];
        return dp[k][i]=triangle[k][i]+min(solve(sum,k+1,i,triangle,dp),solve(sum,k+1,i+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),INT_MIN));
        return solve(0,0,0,triangle,dp);
    }
};