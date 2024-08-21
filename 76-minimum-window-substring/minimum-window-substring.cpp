class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n=s.size(),m=t.size();
        if(m>n)return "";
        for(int i=0;i<m;i++) mp[t[i]]++;

        int countReqd=m;
        int minWinSiz=INT_MAX;
        int i=0,j=0;
        int substrStart=0;

        
        while(j<n){
            if(mp[s[j]]>0)countReqd--;
            mp[s[j]]--;

            while(countReqd==0){
                if(j-i+1<minWinSiz){
                    minWinSiz=j-i+1;
                    substrStart=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    countReqd++;
                }
                i++;
            }
            j++;
        }
        if(minWinSiz==INT_MAX)return "";
        return s.substr(substrStart,minWinSiz);
    }
};