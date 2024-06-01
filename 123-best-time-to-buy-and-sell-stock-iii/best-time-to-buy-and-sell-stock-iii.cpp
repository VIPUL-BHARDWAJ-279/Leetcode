class Solution {
public:
    // int solve( int day, int tran , vector<int>& prices, vector<vector<int>> & dp){
    //     if(day==prices.size()  ||  tran ==2*2)return 0;
    //     if(dp[day][tran]!=-1) return dp[day][tran];
    //     if(tran % 2 == 0){ // Buy
    //         return dp[day][tran]=max(-prices[day]+solve(day+1,tran+1, prices,dp), solve(day+1,tran,prices,dp)); // tran = number of transactions done
    //     }
    //     else return dp[day][tran]=max(prices[day] + solve(day+1,tran+1,prices,dp),solve(day+1,tran,prices,dp));
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>> dp(n,vector<int>(4,-1));
    //     return solve(0,0,prices,dp);
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int day=n-1;day>=0;day--){
            for(int tran=2*k-1;tran>=0;tran--){
                if(tran % 2 == 0) dp[day][tran]=max(-prices[day] + dp[day+1][tran+1], dp[day+1][tran]);
                else dp[day][tran]=max(prices[day] + dp[day+1][tran+1], dp[day+1][tran]);
            }
        }
        return dp[0][0];
        
    }
};