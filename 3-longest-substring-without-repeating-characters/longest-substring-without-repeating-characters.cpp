class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size(),maxLen=0,l=0,r=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l)l=mp[s[r]]+1;
            }
            maxLen=max(maxLen,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};