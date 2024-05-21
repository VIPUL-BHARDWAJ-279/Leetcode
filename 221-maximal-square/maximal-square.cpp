#include<bits/stdc++.h>
class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& mat) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        int m=mat.size(),n=mat[0].size(),side=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || mat[i][j]=='0')dp[i][j]=mat[i][j]-'0';
                else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                side=max(side,dp[i][j]);
            }
        }
        return side*side;
    }
};