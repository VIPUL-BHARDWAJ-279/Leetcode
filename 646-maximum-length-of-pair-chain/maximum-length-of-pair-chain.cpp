class Solution {
public:

    // int lis(int ind, int top, vector<vector<int>> & a, vector<vector<int>> & dp){ //top == previous taken index
    //     if(ind==a.size())return 0; // here we are returning the size of the lis from index=ind to index=a.size()-1
    //     if(dp[ind][top+1]!=-1)return dp[ind][top+1];
    //     int len= 0+lis(ind+1,top,a,dp);
    //     if(top==-1 || a[ind][0]>a[top][1])len=max(len,1+lis(ind+1,ind,a,dp));
    //     return dp[ind][top+1]= len;
    // }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(),pairs.end());
    //     vector<vector<int>> dp(pairs.size(),vector<int>(pairs.size()+1,-1));
    //     return lis(0,-1,pairs,dp);
    // }
    static bool compi(vector<int> & a, vector<int> & b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs){
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        sort(pairs.begin(),pairs.end(),compi);
        int ans=1,prevEnd=pairs[0][1];

        for(int i=1;i<pairs.size();i++)if(prevEnd<pairs[i][0])prevEnd=pairs[i][1],ans++;
        return ans;
    }
};