class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),oddCnt=0,ans=0;
        unordered_map<int,int> mp; // mp will store frequency of odd counts
        mp[0]=1; // we have seen '0' odd count 1 time as we are starting with oddCnt=0
        for(int i=0;i<n;i++){
            if(nums[i]%2)oddCnt++;
            ans+=mp[oddCnt-k];
            mp[oddCnt]++;
        }
        return ans;
        
    }
};