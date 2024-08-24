class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int n=a.size(),s=0,e=n-1;

        int f=-1,l=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(a[mid]==target){
                f=mid;
                e=mid-1;
            }
            else if(a[mid]<target)s=mid+1;
            else e=mid-1;
        }

        s=0,e=n-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(a[mid]==target){
                l=mid;
                s=mid+1;
            }
            else if(a[mid]<target)s=mid+1;
            else e=mid-1;
        }

        return {f,l};
    }
};