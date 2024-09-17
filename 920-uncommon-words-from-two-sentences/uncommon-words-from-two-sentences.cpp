class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        s1+=' ';
        s2+=' ';
        string word="";
        unordered_map<string,int>mp;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                mp[word]++;
                word="";
            }
            else word+=s1[i];
        }
        word="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                mp[word]++;
                word="";
            }
            else word+=s2[i];
        }
        for(auto & x:mp){
            if(x.second==1)ans.push_back(x.first);
        }
        return ans;
    }
};