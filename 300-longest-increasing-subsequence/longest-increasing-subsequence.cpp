class Solution {
public:
    // int lis(int ind, int top, vector<int> & a, vector<vector<int>> & dp){ //top == previous taken index
    //     if(ind==a.size())return 0; // here we are returning the size of the lis from index=ind to index=a.size()-1
    //     if(dp[ind][top+1]!=-1)return dp[ind][top+1];
    //     int take=0;
    //     if(top==-1 || a[ind]>a[top])take= 1+lis(ind+1,ind,a,dp);
    //     int notTake= 0+lis(ind+1,top,a,dp);
    //     return dp[ind][top+1]= max(take,notTake);
    // }


    // int lengthOfLIS(vector<int>& a){
    //     vector<vector<int>> dp(a.size(),vector<int>(a.size()+1,-1));
    //     return lis(0,-1,a,dp);
    // }

    // int lengthOfLIS(vector<int>& a){ //tabulation
    //     int n=a.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // here we have done coordinate shifting for 'top' as it ranges from -1 to n-1
    //                                                     // therefore to make it from 0 to n, we always add '1' to everything written in second dimension of dp

    //     for(int j=0;j<n+1;j++)dp[n][j]=0;

    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int top=ind-1;top>=-1;top--){
    //             int take=0;
    //             if(top==-1 || a[ind]>a[top])take=1+dp[ind+1][ind+1];
    //             int notTake=dp[ind+1][top+1];
    //             dp[ind][top+1]=max(take,notTake);
    //         }
    //     }
    //     return dp[0][-1+1];
    // }

    int lengthOfLIS(vector<int>& a){ //tabulation + space optimization
        int n=a.size();
        vector<int> curr(n+1,0),nexti(n+1,0); // here we have done coordinate shifting for 'top' as it ranges from -1 to n-1
                                                        // therefore to make it from 0 to n, we always add '1' to everything written in second dimension of dp


        for(int ind=n-1;ind>=0;ind--){
            for(int top=ind-1;top>=-1;top--){
                int take=0;
                if(top==-1 || a[ind]>a[top])take=1+nexti[ind+1];
                int notTake=nexti[top+1];
                curr[top+1]=max(take,notTake);
            }
            nexti=curr;
        }
        return nexti[-1+1];
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