class Solution {
public:
    int f(int i, int j, string & s1, string & s2, vector<vector<int>> & dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j])return dp[i][j]=f(i-1,j-1,s1,s2,dp);

        int replace=1+f(i-1,j-1,s1,s2,dp);
        int insert=1+f(i,j-1,s1,s2,dp);
        int del=1+f(i-1,j,s1,s2,dp);

        return dp[i][j]=min(replace,min(insert,del));

    }
    int minDistByTabulation(string & word1, string & word2){
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n+1;i++)dp[i][0]=i+1;
        for(int j=0;j<m+1;j++)dp[0][j]=j+1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];

                else{
                    int replace=1+dp[i-1][j-1];
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];

                    dp[i][j]=min(replace,min(insert,del));
                }
            }
        }
        return dp[n][m]-1;
    }

    
    int minDistance(string word1, string word2) {
        // if(word1=="" && word2=="")return 0;
        // int n=word1.size(),m=word2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,word1,word2,dp);
        return minDistByTabulation(word1,word2);

    }
};