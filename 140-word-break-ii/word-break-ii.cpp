class Solution {
public:

    void solve(int i, string & s,string temp,vector<string> & ans, unordered_set<string> & bank){
        if(i==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
 
        string word="";
        for(int j=i;j<s.size();j++){
            word+=s[j];
            if(bank.find(word)!=bank.end()){
                string prev=temp;
                temp+=word;
                temp+=' ';

                solve(j+1,s,temp,ans,bank);

                temp=prev;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        vector<string> ans;
        unordered_set<string> bank(wordDict.begin(),wordDict.end());

        solve(0,s,"",ans,bank);
        return ans;
    }
};