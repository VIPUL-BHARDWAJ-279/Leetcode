class Solution {
public:
    int f(int i, int j, string & s1, string & s2, vector<vector<int>> & dp){

        if(j==0)return 1;
        if(i==0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i-1]==s2[j-1])return dp[i][j]=f(i-1,j,s1,s2,dp)+f(i-1,j-1,s1,s2,dp); // delete + no delete
        else return dp[i][j]=f(i-1,j,s1,s2,dp); // delete only

    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return f(n,m,s,t,dp);
    }
};