class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)dp[n-1][j]=mat[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int lower_left=INT_MAX,lower_right=INT_MAX,lower_bottom=dp[i+1][j];
                if(j>0)lower_left=dp[i+1][j-1];
                if(j<n-1)lower_right=dp[i+1][j+1];

                dp[i][j]=mat[i][j]+min(lower_bottom,min(lower_left,lower_right));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++)mini=min(mini,dp[0][j]);
        return mini;
    }
};