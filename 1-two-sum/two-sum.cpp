class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++){     
            int rem=target-a[i];
            if(mp.find(rem)!=mp.end())return {mp[rem],i};
            mp[a[i]]=i;
        }
        return {-1,-1};
    }
};