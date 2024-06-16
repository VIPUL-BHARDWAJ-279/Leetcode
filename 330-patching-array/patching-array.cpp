class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // maxReach = maxReachable number after summing some or all elements from the array considered till now
        long long maxReach=0,patches=0,i=0;

        while(maxReach<n){
            if(i<nums.size() && nums[i]<=maxReach+1)maxReach+=nums[i],i++;
            else{
                //patch or add number=(maxReach+1)
                maxReach+=(maxReach+1);
                patches++;
            }
        }
        return patches;
    }
};