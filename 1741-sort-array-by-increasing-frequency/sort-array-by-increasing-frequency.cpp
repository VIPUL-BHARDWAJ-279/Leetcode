class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;

        auto compi=[&mp](int a,int b){  // Custom Comparator
            if(mp[a]==mp[b])return b<a;
            return mp[a]<mp[b];
        };

        sort(nums.begin(),nums.end(),compi);
        return nums;
    }
};