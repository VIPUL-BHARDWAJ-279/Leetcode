class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
        
        if(m*n!=a.size())return {};
        vector<vector<int>> ans(m,vector<int>(n,0));
        int x=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=a[x];
                x++;
            }
        }
        return ans;
    }
};