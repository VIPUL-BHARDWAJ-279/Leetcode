class Solution {
public:
    int solve(int  i,int  j, string & s , string & t, vector<vector<int>> & dp){
        if(i==s.size() || j==t.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0,notTake=0;
        if(s[i]==t[j])take=1+solve(i+1,j+1,s,t,dp);
        if(s[i]!=t[j]) notTake=max(solve(i+1,j,s,t,dp),solve(i,j+1,s,t,dp));
        return dp[i][j]=max(take,notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
    }
};