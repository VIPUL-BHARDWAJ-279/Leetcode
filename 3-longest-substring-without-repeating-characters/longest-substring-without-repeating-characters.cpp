class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),start=0,end=0,maxi=0;
        unordered_map<char,int>mp;
        for(end=0;end<n;end++){
            if(mp.find(s[end])!=mp.end()){ // current char pehle se hi hai
                if(mp[s[end]]>=start)start=mp[s[end]]+1; // aur wo current window ke andar hai
            }
            maxi=max(maxi,end-start+1);
            mp[s[end]]=end;
        }

        return maxi;
    }
};