class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
             long long ans=0,wantToIncrease=0,sacrifice=INT_MAX;
             for(auto num:nums){
                if((num^k)>num){
                    ans+=(num^k);
                    sacrifice=min(sacrifice,(long long)(num^k)-num);
                    wantToIncrease++;
                }
                else{
                    ans+=num;
                    sacrifice=min(sacrifice,num-(long long)(num^k));
                }
             }
             if(wantToIncrease%2==0)return ans;
             else return ans-sacrifice;
    }
};