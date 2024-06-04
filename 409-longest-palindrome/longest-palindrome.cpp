class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int totalEven=0,totalOdd=0,oddi=0;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        for(auto x:mp){
            if(x.second%2==0)totalEven+=x.second;
            else totalOdd+=x.second-1,oddi=1;;
        }
        return totalEven+totalOdd+oddi;
    }
};