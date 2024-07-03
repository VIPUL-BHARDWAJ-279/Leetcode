class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)return 0;
        int n=nums.size(),mini=INT_MAX; 
        sort(nums.begin(),nums.end());
        int s=0,e=n-4;
        while(e<n)mini=min(mini,nums[e++]-nums[s++]);
        return mini==INT_MAX?0:mini;
    }
};