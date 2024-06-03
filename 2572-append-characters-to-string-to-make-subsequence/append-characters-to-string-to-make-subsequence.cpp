class Solution {
public:
    int appendCharacters(string s, string t) {
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[x])x++;
        }
        return t.size()-x;
    }
};