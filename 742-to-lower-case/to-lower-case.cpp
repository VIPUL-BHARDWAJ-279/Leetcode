class Solution {
public:
    bool isUpperCase(char & ch){
        return (ch>='A' && ch<='Z');
    }
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            if(isUpperCase(s[i]))s[i]='a'+s[i]-'A';
        }
        return s;
    }
};