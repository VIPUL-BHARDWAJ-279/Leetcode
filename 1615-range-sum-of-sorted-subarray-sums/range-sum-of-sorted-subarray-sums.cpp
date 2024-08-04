class Solution {
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        int mod=1e9+7;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                sum%=mod;
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        int sum=0;
        for(int i=left-1;i<=right-1;i++){
            sum+=ans[i];
            sum%=mod;
        }
        return sum;
    }
};