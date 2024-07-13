class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        int mini=INT_MAX;
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(a[s]<=a[mid])mini=min(mini,a[s]),s=mid+1;
            else mini=min(mini,a[mid]),e=mid-1;
        }
        return mini;
    }
};