class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end())mp[s].push_back(str);
            else mp[s]={str};
        }

        vector<vector<string>> ans;
        for(auto x:mp)ans.push_back(x.second);
        return ans;
    }
};