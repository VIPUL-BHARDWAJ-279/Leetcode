class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),maxLen=2;
        vector<vector<int>> t(n,vector<int>(1001,0)); // common diff € [0,500] therefore, add 500 to each common difference for coordinate shifting

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+500; // To avoid negative index of dp
                if(t[j][diff]>0)t[i][diff] = t[j][diff]+1;
                else t[i][diff]=2;
                maxLen=max(maxLen,t[i][diff]);

            }
        }
        return maxLen;
    }
};