class Solution {
public:
    bool isPalindrome(string & s, int start, int end){
        while(start<end)if(s[start++]!=s[end--])return false;
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
        string ans="";
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(isPalindrome(s,i,j) && j-i+1>maxi){
                    ans=s.substr(i,j-i+1);
                    maxi=j-i+1;
                }
            }
        }
        return ans;
    }
};