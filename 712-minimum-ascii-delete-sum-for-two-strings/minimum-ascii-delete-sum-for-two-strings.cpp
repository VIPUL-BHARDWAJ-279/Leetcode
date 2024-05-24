class Solution {
public:
    int f(int i, int j, string & s1, string & s2, vector<vector<int>> & dp){
        if(i==0 && j==0)return 0;
        if(i==0){
            int sum=0;
            for(int k=0;k<j;k++)sum+=s2[k];
            return sum;
        }
        if(j==0){
            int sum=0;
            for(int k=0;k<i;k++)sum+=s1[k];
            return sum;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i-1]==s2[j-1])return dp[i][j]=f(i-1,j-1,s1,s2,dp);

 
        int del1=(s1[i-1])+f(i-1,j,s1,s2,dp);
        int del2=(s2[j-1])+f(i,j-1,s1,s2,dp);

        return dp[i][j]=min(del1,del2);

    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s1,s2,dp);
    }
};