class Solution {
public:
    // int dp[100001][2][101];
    // int solve(int day,int tDone,int & k, bool canBuy,vector<int> & prices){
    //     if(day==prices.size() || tDone==k)return 0;

    //     if(dp[day][canBuy][tDone]!=-1)return dp[day][canBuy][tDone];

    //     if(canBuy){
    //         int buy= -prices[day] + solve(day+1, tDone, k, !canBuy, prices);
    //         int notBuy= solve(day+1, tDone, k, canBuy, prices);
    //         return dp[day][canBuy][tDone]=max(buy,notBuy);
    //     }
    //     else{
    //         int sell= prices[day] + solve(day+1, tDone+1, k, !canBuy, prices);
    //         int notSell= solve(day+1, tDone, k, canBuy, prices);
    //         return dp[day][canBuy][tDone]=max(sell,notSell);
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     memset(dp,-1,sizeof(dp));
    //     int transactionsDone=0;
    //     return solve(0,transactionsDone,k,true,prices);
    // }

        int maxProfit(int k, vector<int>& prices){
            int n=prices.size();
            vector<int> curr(2*k+1,0),nexti(2*k+1,0);
            for(int day=n-1;day>=0;day--){
                for(int tran=2*k-1;tran>=0;tran--){
                    if(tran % 2 == 0) curr[tran]=max(-prices[day] + nexti[tran+1], nexti[tran]);
                    else curr[tran]=max(prices[day] + nexti[tran+1], nexti[tran]);
                }
                nexti=curr;
            }
            return curr[0];
        }

};