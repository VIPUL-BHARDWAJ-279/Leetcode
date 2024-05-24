class Solution {
public:
    int lcs(int ind1, int ind2, string & s1, string & s2, vector<vector<int>> & dp){
        if(ind1==0 || ind2==0)return 0;
        if(dp[ind1-1][ind2-1]!=-1)return dp[ind1-1][ind2-1];

        if(s1[ind1-1]==s2[ind2-1])return dp[ind1-1][ind2-1]= 1 + lcs(ind1-1,ind2-1,s1,s2,dp);
        else return dp[ind1-1][ind2-1]= max(lcs(ind1-1,ind2,s1,s2,dp),lcs(ind1,ind2-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string reversedS="";
        for(int i=n-1;i>=0;i--)reversedS+=s[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));

        // for(int i=0;i<n;i++)dp[i][0]=0;
        return lcs(n,n,s,reversedS,dp);
    }
};