class Solution {
public:
    // int lcs(int ind1, int ind2, string & s1, string & s2, vector<vector<int>> & dp){
    //     if(ind1<0 || ind2<0)return dp[ind1][ind2]=0;
    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    //     if(s1[ind1]==s2[ind2])return dp[ind1][ind2]= 1 + lcs(ind1-1,ind2-1,s1,s2,dp);
    //     else return dp[ind1][ind2]= max(lcs(ind1-1,ind2,s1,s2,dp),lcs(ind1,ind2-1,s1,s2,dp));
    // }
    // int lcsByTabulation(string & s, string & r){
    //     int n=s.size(),m=r.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    //     for(int i=0;i<n;i++)dp[i][0]=0;
    //     for(int j=0;j<m;j++)dp[0][j]=0;

    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<m+1;j++){
    //             if(s[i-1]==r[j-1])dp[i][j]= 1 + dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n][m];
    // }
    int lcsByTabulationOptimized(string & s, string & r){
        int n=s.size(),m=r.size();

        //we take 2 rows only- 
        // 1) prev - to represent dp[i-1]
        // 2) curr - to represent dp[i]
        //  First initialize them correctly and
        //  then replace all the occurences of dp[i-1] with prev and dp[i] with curr

        vector<int> prev(m+1,0),curr(m+1,0);

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==r[j-1])curr[j]= 1 + prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[m];
    }
    int longestPalindromeSubseq(string s) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int n=s.size();
        string reversedS="";
        for(int i=n-1;i>=0;i--)reversedS+=s[i];
        // return lcs(n,n,s,reversedS,dp);
        // return lcsByTabulation(s,reversedS);
        return lcsByTabulationOptimized(s,reversedS);

    }
};