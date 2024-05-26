class Solution {
public:

    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> lisLen(n,1),count(n,1); // lisLen[i] will give length of lis ending at index i  & count[i] will give Count of lis till that index

        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(lisLen[i]==lisLen[j]+1)count[i]+=count[j];
                    else if(lisLen[i]<lisLen[j]+1){
                        count[i]=count[j];
                        lisLen[i]=max(lisLen[i],lisLen[j]+1);
                    }
                }
            }
            maxLen=max(maxLen,lisLen[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)if(lisLen[i]==maxLen)ans+=count[i];
        return ans;
    }
};