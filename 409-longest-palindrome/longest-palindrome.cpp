class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans=0,oddi=0;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        for(auto x:mp){
            if(x.second%2==0)ans+=x.second;
            else ans+=x.second-1,oddi=1;;
        }
        return ans+oddi;
    }
};