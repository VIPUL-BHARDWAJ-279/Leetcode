class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prod=1,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                prod=0;
                break;
            }
            else if(nums[i]<0)cnt++;
        }
        if(prod==0)return 0;
        if(cnt%2==0)return 1;
        return -1;
    }
};