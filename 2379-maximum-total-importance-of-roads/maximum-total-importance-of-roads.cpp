class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n,0);
        long long ans=0;
        for(auto & v:roads){
            degrees[v[0]]++;
            degrees[v[1]]++;
        }
        sort(degrees.begin(),degrees.end());
        int k=1;
        for(int i=0;i<n;i++){
            ans+=(long long)(degrees[i]*1ll*k);
            k++;
        }
        return ans;
    }
};