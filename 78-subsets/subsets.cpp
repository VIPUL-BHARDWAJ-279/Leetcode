class Solution {
public:
    void solve(vector<vector<int>> &v, vector<int> &temp, vector<int> &nums, int i){        
        if(i==nums.size()){
            v.push_back(temp);
            return;
        }

        solve(v,temp,nums,i+1);

        temp.push_back(nums[i]);
        solve(v,temp,nums,i+1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        solve(v,temp,nums,0);
        return v;
    }
};