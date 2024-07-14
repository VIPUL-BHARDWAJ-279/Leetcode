class Solution {
public:

    void solve(int i,vector<int> & nums, int target, vector<int>& temp, vector<vector<int>> & ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size() || target<0)return;

        solve(i+1,nums,target,temp,ans);
        int j;
        for(j=nums[i];j<=target;j+=nums[i]){
            temp.push_back(nums[i]);
        }
        j-=nums[i];
        for(j;j>=nums[i];j-=nums[i]){
            solve(i+1,nums,target-j,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,target,temp,ans);
        return ans;
    }
};