class Solution {
public:
    int solve(int i,vector<int>& nums, int k, unordered_map<int,int> & mp){
        if(i==nums.size())return 1;
        int pick=0;
        if(mp[nums[i]+k]==0 && mp[nums[i]-k]==0){
            mp[nums[i]]++;
            pick=solve(i+1,nums,k,mp);
            mp[nums[i]]--;
        }
        int notpick=solve(i+1,nums,k,mp);

        return pick+notpick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int ans=solve(0,nums,k,mp);
        return ans-1;
    }
};