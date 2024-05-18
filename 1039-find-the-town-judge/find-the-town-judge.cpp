class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        
        int trustOfNode[1001]={0};
        for(auto x:trust){
            trustOfNode[x[0]]--;
            trustOfNode[x[1]]++;
        }
        for(int i=1;i<1001;i++)if(trustOfNode[i]==n-1)return i;
        return -1;  
    }
};