class Solution {
public:
    int solve(vector<int> & a,int  sum, int i, vector<int> & dp){
        if(i >=a.size())return 0;
        // if(i==a.size()-1)return dp[i]=sum+a[a.size()-1];

        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(a[i]+solve(a,sum,i+2,dp),solve(a,sum,i+1,dp));  
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int sum=0;
        return solve(nums,sum,0,dp);
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