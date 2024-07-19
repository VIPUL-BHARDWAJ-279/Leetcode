class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> ans;
        set<pair<int,int>> rowmin;

        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            int cind=-1;
            for(int j=0;j<n;j++){
                if(mat[i][j]<mini){
                    mini=mat[i][j];
                    cind=j;
                }
            }
            rowmin.insert({i,cind});
        }


        for(int j=0;j<n;j++){
            int maxi=INT_MIN;
            int rind=-1;
            for(int i=0;i<m;i++){
                if(mat[i][j]>maxi){
                    maxi=mat[i][j];
                    rind=i;
                }
            }
            if(rowmin.find({rind,j})!=rowmin.end())ans.push_back(mat[rind][j]);
        }

        return ans;
    }
};