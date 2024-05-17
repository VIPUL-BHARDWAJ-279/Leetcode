class Solution {
public:
    int solve(vector<int> & a,int & sum, int i, vector<int> & dp){
        if(i ==a.size())return dp[i]=sum;
        if(i==a.size()-1)return dp[i]=sum+a[a.size()-1];
        if(dp[i]!=-1)return dp[i];

        return dp[i]=max(a[i]+solve(a,sum,i+2,dp),solve(a,sum,i+1,dp));
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int sum=0;
        return max(solve(nums,sum,0,dp),solve(nums,sum,1,dp));
    }
};