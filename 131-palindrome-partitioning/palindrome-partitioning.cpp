class Solution {
public:
    bool isPalindrome(string & s, int start, int end){
        while(start<=end)if(s[start++]!=s[end--])return false;
        return true;
    }
    void solve(int start, string & s, vector<string> & path, vector<vector<string>> & ans){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(isPalindrome(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                solve(end+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int start=0;
        solve(start,s,path,ans);
        return ans;
    }
};