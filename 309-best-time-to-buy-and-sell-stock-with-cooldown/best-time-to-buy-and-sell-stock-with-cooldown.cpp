class Solution {
public:
    int dp[5001][2];
    int solve(int i,vector<int>& prices, int canBuy){
        if(i>=prices.size())return 0;
        if(dp[i][canBuy]!=-1)return dp[i][canBuy];
        int profitFromBuying=0,profitFromSelling=0,profitFromDoingNothing=0;
        
        if(canBuy)profitFromBuying=solve(i+1,prices,0)-prices[i];
        else profitFromSelling=solve(i+2,prices,1)+prices[i];
        profitFromDoingNothing=solve(i+1,prices,canBuy);

        return dp[i][canBuy]=max(profitFromDoingNothing,max(profitFromBuying,profitFromSelling));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,1);
    }
};