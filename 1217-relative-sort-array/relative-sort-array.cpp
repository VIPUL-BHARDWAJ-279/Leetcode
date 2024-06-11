class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        map<int,int> mp;
        for(int i=0;i<a.size();i++)mp[a[i]]++;
        vector<int> ans;
        for(auto num:b){
            while(mp[num]!=0){
                ans.push_back(num);
                mp[num]--;
            }
        }
        for(auto x:mp){
            int num=x.first,freq=x.second;
            while(freq--){
                ans.push_back(num);
            }
        }

        return ans;
    }
};