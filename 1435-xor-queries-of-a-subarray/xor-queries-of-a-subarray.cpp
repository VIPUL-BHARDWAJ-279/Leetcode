class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n=a.size(),xori=1;
        vector<int>prexor(n+1,1),ans;

        for(int i=0;i<n;i++){
            xori=xori^a[i];
            prexor[i+1]=xori;
        }

        for(auto &q:queries){
            int l=q[0],r=q[1];
            ans.push_back(prexor[l]^prexor[r+1]);
        }
        return ans;
    }
};