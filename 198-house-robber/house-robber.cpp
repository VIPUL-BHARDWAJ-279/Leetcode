class Solution {
public:
    int solve(int i, vector<int> & nums, vector<int> & dp){
        if(i==0)return nums[i];
        if(i<0)return 0;

        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+solve(i-2,nums,dp);
        int notPick=solve(i-1,nums,dp);
        return dp[i]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums.size()-1,nums,dp);
    }


    // Tabulation + Optimization
    // int rob(vector<int> & nums){
    //     int prev1=0,prev2=0,dp;
    //     for(auto num:nums){
    //         dp=max(prev1,prev2+num);
    //         prev2=prev1;
    //         prev1=dp;
    //     }
    //     return dp;
    // }
};