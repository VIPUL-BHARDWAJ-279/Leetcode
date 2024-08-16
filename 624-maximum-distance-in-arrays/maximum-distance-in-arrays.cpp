class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> a,b;
        for(int i=0;i<arrays.size();i++){
            a.push_back({arrays[i].back(),i});
            b.push_back({arrays[i][0],i});
        }
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        sort(b.begin(),b.end());

        if(a[0].second!=b[0].second)return a[0].first-b[0].first;
        else{
            return max(a[0].first-b[1].first,a[1].first-b[0].first);
        }
        

    }
};