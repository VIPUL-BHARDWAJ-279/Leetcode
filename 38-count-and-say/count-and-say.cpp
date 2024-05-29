class Solution {
public:
    
    string RLE(string & s){
        int n=s.size(),cnt=0;
        char ch=s[0];
        string ans="";

        for(auto x:s){
            if(x==ch)cnt++;
            else{
                ans+=to_string(cnt) + ch;
                ch=x;
                cnt=1;
            }
        }
        ans+=to_string(cnt);
        ans+=ch;

        return ans;
    }

    string countAndSay(int n){
        if(n==1)return "1";
        string temp=countAndSay(n-1);
        return RLE(temp);
    }

    // string CandS(int n, vector<string> & dp){
    //     if(n==1)return "1";
    //     if(dp[n]!="")return dp[n];

    //     string temp=CandS(n-1,dp);
    //     return dp[n]=RLE(temp);
    // }

    // string countAndSay(int n) {
    //     vector<string> dp(n+1,"");
    //     return CandS(n,dp);
    // }
};