class Solution {
public:
    int tri(int n,vector<int> & dp){
        if(n==0)return dp[0]=0;
        if(n==1 || n==2)return dp[1]=1;
        if(dp[n]!=-1)return dp[n];
        else return dp[n]=tri(n-1,dp)+tri(n-2,dp)+tri(n-3,dp);
    }
    int tribonacci(int n){
        vector<int> dp(n+1,-1);
        return tri(n,dp);
    }
    // Iterative Code
    // int tribonacci(int n) {
    //     long long t0=0,t1=1,t2=1;
    //     for(int i=0;i<n;i++){
    //         int temp=t0;
    //         t0=t1;
    //         t1=t2;
    //         t2=temp+t0+t1;
    //     }
    //     return int(t0);
    // }
};