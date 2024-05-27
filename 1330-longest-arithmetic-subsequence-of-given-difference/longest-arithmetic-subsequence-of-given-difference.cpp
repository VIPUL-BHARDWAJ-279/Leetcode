class Solution {
public:

    // First two codes will give MLE and TLE
    // Using hashmap is best
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

    // int longestSubsequence(vector<int>& a, int difference) {
    //     int n=a.size();
    //     vector<int> curr(n+1,0),nexti(n+1,0);
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int top=ind-1;top>=-1;top--){
    //             int len= nexti[top+1];
    //             if(top==-1 || a[ind]-a[top]==difference)len=max(len,1+nexti[ind+1]);
    //             curr[top+1]= len;
    //         }
    //         nexti=curr;
    //     }
    //     return nexti[-1+1];
    // }

    int longestSubsequence(vector<int>& a, int difference){
        unordered_map<int,int> length;
        int ans=1;
        for( auto x:a){
            ans=max(ans,length[x]=1+length[x-difference]);
        }
        return ans;
    }
};