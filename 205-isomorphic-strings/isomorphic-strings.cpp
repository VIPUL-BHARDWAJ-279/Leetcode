class Solution {
public:
    // bool isIsomorphic(string s, string t) {
    //     ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //     if(s.size()!=t.size())return false;
    //     unordered_map<char,char> m1,m2;
    //     for(int i=0;i<s.size();i++){
    //         if(!m1[s[i]] && !m2[t[i]]){
    //             m1[s[i]]=t[i];
    //             m2[t[i]]=s[i];
    //         }
    //         else if(m1[s[i]]!=t[i])return false;
    //     } 
    //     return true;
    // }


    bool isIsomorphic(string s, string t){
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        unordered_map<char,int> mps,mpt;
        if(s.size()!=t.size())return false;

        for(int i=0;i<s.size();i++){
            if(mps[s[i]]!=mpt[t[i]])return false;
            mps[s[i]]=i+1;
            mpt[t[i]]=i+1;
        }

        return true;
    }
};