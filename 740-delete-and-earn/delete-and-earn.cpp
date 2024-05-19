class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)maxi=max(maxi,nums[i]);

        vector<int> sumi(maxi+1,0);
        for(int i=0;i<nums.size();i++)sumi[nums[i]]+=nums[i];

        for(int i=2;i<sumi.size();i++){
            sumi[i]=max(sumi[i-1],sumi[i-2]+sumi[i]);
        }
        return sumi.back();
    }
};