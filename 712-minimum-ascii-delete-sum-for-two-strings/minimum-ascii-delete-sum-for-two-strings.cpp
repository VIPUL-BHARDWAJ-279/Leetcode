class Solution {
public:
    // int f(int i, int j, string & s1, string & s2, vector<vector<int>> & dp){
    //     if(dp[i][j]!=-1)return dp[i][j];

    //     if(i==0 || j==0)return dp[i][j]=0;
    //     if(i==0){
    //         int sum=0;
    //         for(int k=0;k<j;k++)sum+=s2[k];
    //         return dp[i][j]=sum;
    //     }
    //     if(j==0){
    //         int sum=0;
    //         for(int k=0;k<i;k++)sum+=s1[k];
    //         return dp[i][j]=sum;
    //     }

    //     if(s1[i-1]==s2[j-1])return dp[i][j]=f(i-1,j-1,s1,s2,dp);

 
    //     int del1=(s1[i-1])+f(i-1,j,s1,s2,dp);
    //     int del2=(s2[j-1])+f(i,j-1,s1,s2,dp);

    //     return dp[i][j]=min(del1,del2);

    // }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // return f(n,m,s1,s2,dp);
        for(int j=1;j<n+1;j++)dp[0][j]= dp[0][j-1]+s2[j-1];

        for(int i=1;i<m+1;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
               
    }
};