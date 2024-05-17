class Solution {
public:
    int climb(int i, vector<int> & cost,int n, vector<int> & dp){
        if(i==n)return dp[n]=0;
        if(i==n-1)return dp[n-1]=cost[n-1];
        if(dp[i]!=-1)return dp[i];
        else return dp[i]=cost[i]+min(climb(i+1,cost,n,dp),climb(i+2,cost,n,dp)); 
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(climb(0,cost,n,dp),climb(1,cost,n,dp));
    }
};