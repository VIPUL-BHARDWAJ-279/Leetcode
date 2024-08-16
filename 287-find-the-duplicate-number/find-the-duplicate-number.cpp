class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int cnt=0; // cnt represents count of numbers in nums which are <= mid
            for(int i=0;i<n;i++)if(nums[i]<=mid)cnt++;

            if(cnt<=mid)s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};