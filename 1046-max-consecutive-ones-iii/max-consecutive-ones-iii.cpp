class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n=a.size(),l=0,r=0,maxLen=0;
        int E=k;

        while(r<n){
            if(a[r]==0)k--;
            if(k<0){
                    k+=!a[l];
                    l++;
                // while(k<0 && l<n){
                // }
            }
           if(k>=0) maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};