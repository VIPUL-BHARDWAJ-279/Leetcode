class Solution {
public:
    bool isFound(string & needle, string & haystack, int s){
        for(int i=0;i<needle.size();i++)if(needle[i]!=haystack[i+s])return false;
        return true;
    }
    int strStr(string haystack, string needle) {
        int k=0;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                if(isFound(needle,haystack,i))return i;
            }
        }
        return -1;
    }
};