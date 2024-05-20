class Solution {
public:
    
    int solve(int i, int sum, vector<int> & nums){
        if(i==nums.size())return sum;
        return solve(i+1,sum^nums[i],nums)+solve(i+1,sum,nums);
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,0,nums);
    }
};