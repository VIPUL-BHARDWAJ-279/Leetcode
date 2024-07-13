class Solution {
public:
    int solve(vector<int> & coins, int remaining,unordered_map<int,int> & mp){  //remaining==remaining amount
        if(remaining<0)return INT_MAX;
        if(remaining==0)return 0;

        if(mp.find(remaining)!=mp.end())return mp[remaining];
        int minCoins=INT_MAX;
        for(auto coin:coins){
            int ans=solve(coins,remaining-coin,mp);
            if(ans!=INT_MAX)minCoins=min(minCoins,ans+1);
        }
        return mp[remaining]=minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> mp;
        int ans=solve(coins,amount,mp);
        return ans==INT_MAX?-1:ans;

    }
};