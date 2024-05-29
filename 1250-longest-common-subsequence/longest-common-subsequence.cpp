class Solution {
public:
    // int dp[1001][1001];
    // int solve(int  i,int  j, string & s , string & t){
    //     if(i==s.size() || j==t.size())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];

    //     if(s[i]==t[j])return dp[i][j]=1+solve(i+1,j+1,s,t);
    //     else return dp[i][j]=max(solve(i+1,j,s,t),solve(i,j+1,s,t));
    // }
    // int longestCommonSubsequence(string s, string t) {
    //     memset(dp,-1,sizeof(dp));
    //     int n=text1.size(),m=text2.size();
    //     return solve(0,0,s,t);
    // }





    // int longestCommonSubsequence(string s, string t){
        
    //     int n=s.size(),m=t.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m-1;j>=0;j--){
    //             if(s[i]==t[j])dp[i][j]=1+dp[i+1][j+1];
    //             else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    // }




    int longestCommonSubsequence(string s, string t){
        
        int n=s.size(),m=t.size();
        vector<int> nexti(m+1,0),curri(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j])curri[j]=1+nexti[j+1];
                else curri[j]=max(nexti[j],curri[j+1]);
            }
            nexti=curri;
        }
        return curri[0];
    }
};