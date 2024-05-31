class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> seti;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(seti.find(nums[i])==seti.end())seti.insert(nums[i]);
            else seti.erase(nums[i]);
        }
        for(auto x:seti)ans.push_back(x);
        return ans;
    }
};