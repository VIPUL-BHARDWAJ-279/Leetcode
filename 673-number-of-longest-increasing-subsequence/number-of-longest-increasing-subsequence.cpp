class Solution {
public:

    int findNumberOfLIS(vector<int>& a) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int n = a.size(),maxLen=1,ans=0;
        vector<int> lisLen(n,1),count(n,1); // lisLen[i] will give length of lis ending at index i  & count[i] will give Count of lis till that index

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(lisLen[i]==lisLen[j]+1)count[i] += count[j];
                    else if(lisLen[j]+1 > lisLen[i]){
                        count[i]=count[j];
                        lisLen[i]=lisLen[j]+1;
                    }
                }
            }
            maxLen=max(maxLen,lisLen[i]);
        }

        for(int i=0;i<n;i++)if(lisLen[i]==maxLen)ans+=count[i];
        return ans;
    }
};