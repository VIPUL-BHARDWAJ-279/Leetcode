class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);
        int x=0;
        for(int i=0;i<s.size();i++)if(s[i]==t[x])x++;
        return t.size()-x;
    }
};