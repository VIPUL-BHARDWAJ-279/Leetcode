class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long pro=1,proUpToFirstNegi=1,ans=INT_MIN;
        for(int i=0;i<n;i++){
            pro*=nums[i];
            if(pro<0)ans=max(ans,pro*proUpToFirstNegi);
            else ans=max(ans,pro);

            if(nums[i]<0 && proUpToFirstNegi==1){
                proUpToFirstNegi=pro;
                pro=1;
            }
            if(pro==0){
                pro=1;
                proUpToFirstNegi=1;
            }

        }
            
        return ans;
    }
};