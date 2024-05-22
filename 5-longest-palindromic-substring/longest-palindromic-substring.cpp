class Solution {
public:
    int isPalindrome(string & str, int s, int e,vector<vector<int>> & dp){
        if(s>=e)return dp[s][e]=1;
        if(dp[s][e]!=-1)return dp[s][e];
        if(str[s]==str[e])return dp[s][e]=isPalindrome(str,s+1,e-1,dp);
        else return dp[s][e]=0;
    }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int maxi=INT_MIN,sp=-1; //sp=starting point
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(isPalindrome(s,i,j,dp)==1){  
                    int len=j-i+1; 
                    if(len>maxi){
                        maxi=len;
                        sp=i;
                    }
                }
            }
        }
        string ans=s.substr(sp,maxi);
        return ans;
    }
};