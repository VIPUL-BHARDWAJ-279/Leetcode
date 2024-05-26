class Solution {
public:
    int lis(int ind, int top, vector<int> & a, vector<vector<int>> & dp){ //top == previous taken index
        if(ind==a.size())return 0; // here we are returning the size of the lis from index=ind to index=a.size()-1
        if(dp[ind][top+1]!=-1)return dp[ind][top+1];
        int take=0;
        if(top==-1 || a[ind]>a[top])take= 1+lis(ind+1,ind,a,dp);
        int notTake= 0+lis(ind+1,top,a,dp);
        return dp[ind][top+1]= max(take,notTake);
    }


    int lengthOfLIS(vector<int>& a){
        vector<vector<int>> dp(a.size(),vector<int>(a.size()+1,-1));
        return lis(0,-1,a,dp);
    }
    // int lengthOfLIS(vector<int>& a) {
        // int n=a.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     int ind=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        //     if(ind==ans.size())ans.push_back(a[i]);
        //     else ans[ind]=a[i];
        // }
        // return ans.size();

    // }
};