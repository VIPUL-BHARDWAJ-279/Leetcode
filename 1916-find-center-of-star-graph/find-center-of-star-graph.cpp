class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        mp[edges[0][0]]++;
        mp[edges[0][1]]++;
        mp[edges[1][0]]++;
        mp[edges[1][1]]++;
        for(auto x:mp){
            if(x.second==2)return x.first;
        }
        return -1;

    }
};