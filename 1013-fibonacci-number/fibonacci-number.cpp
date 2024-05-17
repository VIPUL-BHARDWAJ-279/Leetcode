class Solution {
public:
    int fibonacci(int n, vector<int> & dp){
        if(n==0 || n==1)return n;
        if(dp[n]!=-1)return dp[n];
        else return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    }
    int fib(int n) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        
        vector<int> dp(n+1,-1);
        return fibonacci(n,dp);
    }
};