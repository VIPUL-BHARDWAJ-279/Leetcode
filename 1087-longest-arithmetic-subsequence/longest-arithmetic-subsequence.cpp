class Solution {
public:
    // int lis(int ind, int top,int & difference, vector<int> & a, vector<vector<int>> & dp){ //top == previous taken index
    //     if(ind==a.size())return 0; // here we are returning the size of the lis from index=ind to index=a.size()-1
    //     if(dp[ind][top+1]!=-1)return dp[ind][top+1];
    //     int len= 0+lis(ind+1,top,difference,a,dp);
    //     if(top==-1 || a[ind]-a[top]==difference)len=max(len,1+lis(ind+1,ind,difference,a,dp));
    //     return dp[ind][top+1]= len;
    // }
    // int longestSubsequence(vector<int>& a, int difference){
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     return lis(0,-1,difference,a,dp);
    // }
    int x(vector<int> & nums,int & difference){
        unordered_map<int,int> length;
        int ans=1;
        for(auto x:nums){
            ans=max(ans,length[x]=1+length[x-difference]);
        }
        return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int diff=0,maxEle=*max_element(nums.begin(),nums.end()),maxLen=1;
        int minEle=-maxEle;
        while(minEle<=maxEle){
            maxLen=max(maxLen,x(nums,minEle));
            minEle++;
        }
        return maxLen;
    }
};