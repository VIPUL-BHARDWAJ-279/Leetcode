#include<bits/stdc++.h>
class Solution {
public:
    int dp[301];

    bool solve(int i, string & s, unordered_set<string> & bank){
        if(i==s.size())return dp[i]=1;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(bank.find(temp)!=bank.end())if(solve(j+1,s,bank))return dp[i]=1;
        }
        return dp[i]=0;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> bank(wordDict.begin(),wordDict.end());
        return solve(0,s,bank)==1?true:false;
    }
};