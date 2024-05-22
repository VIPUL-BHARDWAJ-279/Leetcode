class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int n=a.size();
        int j=1;
        while(j<n && a[j]==a[j-1])j++;
        if(j==n)return true;
        bool asc=false,desc=false;
        int diff=a[j]-a[j-1];
        if(diff>0)asc=true;
        else desc=true;
        for(int i=1;i<n;i++){
            diff=a[i]-a[i-1];
            if(asc && diff<0)return false;
            if(desc && diff>0)return false;
        }
        return true;
    }
};