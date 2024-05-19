class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        vector<int> bucket(10001);
        for(auto num:nums)bucket[num]+=num;
        int prev1=0,prev2=0;
        for(auto num:bucket){  // variable order is == [prev2,prev1,dp]
            int dp=max(prev1,prev2+num);
            prev2=prev1;
            prev1=dp;
        }
        return prev1;
    }
};