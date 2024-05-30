class Solution {
public:
    int countTriplets(vector<int>& a) {
        a.insert(a.begin(),0);
        int n=a.size(),ans=0;

        for(int i=1;i<n;i++)a[i]^=a[i-1];
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[i]==a[j])ans+=j-i-1;
        return ans;
    }
};