class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),windowSize=0;
        
        for(int i=0;i<n;i++)if(nums[i]==1)windowSize++;

        int one=0,maxOnesTogether=0;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<windowSize;i++){
            if(nums[i]==1)one++;
        }
        int s=0,e=windowSize-1;
        while(e<nums.size()){
            if(nums[s]==1)one--;
            s++;
            e++;
            if(e<nums.size() && nums[e]==1)one++;
            maxOnesTogether=max(maxOnesTogether,one);
        }

        return windowSize-maxOnesTogether;

    }
};