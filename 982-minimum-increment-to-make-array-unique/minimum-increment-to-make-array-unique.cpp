class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            int diff=nums[i-1]-nums[i];
            if(diff>=0)nums[i]+=(diff+1),cnt+=(diff+1);
        }
        return cnt;
    }
};