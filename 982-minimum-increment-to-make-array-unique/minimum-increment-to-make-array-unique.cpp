class Solution {
public:

    int minIncrementForUnique(vector<int>& nums){
        int n=nums.size(),moves=0;;
        int maxi=*max_element(nums.begin(), nums.end());
        vector<int> freq(n+maxi,0);
        for(int i=0;i<n;i++)freq[nums[i]]++;

        
        
        for(int i=0;i<freq.size();i++){
            if(freq[i]>1){
                int extra=freq[i]-1;
                freq[i+1]+=extra;
                freq[i]=1;

                moves+=extra;
            }
            
        }
        return moves;
    }
    // int minIncrementForUnique(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false),cin.tie(NULL);
    //     int cnt=0;
    //     sort(nums.begin(),nums.end());
    //     for(int i=1;i<nums.size();i++){
    //         int diff=nums[i-1]-nums[i];
    //         if(diff>=0)nums[i]+=(diff+1),cnt+=(diff+1);
    //     }
    //     return cnt;
    // }
};