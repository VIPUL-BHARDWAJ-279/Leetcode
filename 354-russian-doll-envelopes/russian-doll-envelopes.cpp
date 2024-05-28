class Solution {
public:
    static bool compi(vector<int> & a, vector<int> & b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& a) {
        int n=a.size();

        sort(a.begin(),a.end(),compi); // sorting by height & if we encounter same height
                                       // sort by descending order of width
                                       
        // because we have sorted all envolopes of a particular height by descending order of width, one envolope will not interfare with another envolop of same height, if we apply lower_bound i.e. first element greater than equal to itself in lis.

        //we now need to care about only width (index 1)
        // Therefore applying lis on a[i][1] for all i
        vector<int> ans;
        for(int i=0;i<n;i++){
            int ind=lower_bound(ans.begin(),ans.end(),a[i][1])-ans.begin();
            if(ind>=ans.size())ans.push_back(a[i][1]);
            else ans[ind]=a[i][1];
        }
        return ans.size();
    }
};