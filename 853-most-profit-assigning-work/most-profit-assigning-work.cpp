class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);
        
        vector<pair<int,int>> jobProfit;
        for(int i=0;i<profit.size();i++)jobProfit.push_back({difficulty[i],profit[i]});
        sort(jobProfit.begin(),jobProfit.end());
        sort(worker.begin(),worker.end());

        int ans=0,maxi=0,k=0;
        for(int i=0;i<worker.size();i++){
            while(k<jobProfit.size()  &&  jobProfit[k].first<=worker[i]){
                maxi=max(maxi,jobProfit[k].second);
                k++;
            }
            ans+=maxi;
        }
        return ans;
    }
};