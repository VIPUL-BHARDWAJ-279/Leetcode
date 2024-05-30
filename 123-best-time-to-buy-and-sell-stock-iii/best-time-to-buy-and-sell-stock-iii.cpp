class Solution {
public:

    int dp[100001][2][2];
    int solve(int day,int tDone, bool canBuy,vector<int> & prices){
        if(day==prices.size() || tDone==2)return 0;

        if(dp[day][canBuy][tDone]!=-1)return dp[day][canBuy][tDone];

        if(canBuy){
            int buy= -prices[day] + solve(day+1, tDone, !canBuy, prices);
            int notBuy= solve(day+1, tDone, canBuy, prices);
            return dp[day][canBuy][tDone]=max(buy,notBuy);
        }
        else{
            int sell= prices[day] + solve(day+1, tDone+1, !canBuy, prices);
            int notSell= solve(day+1, tDone, canBuy, prices);
            return dp[day][canBuy][tDone]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int transactionsDone=0;
        return solve(0,transactionsDone,true,prices);
    }
};