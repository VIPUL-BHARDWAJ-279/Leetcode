class Solution {
public:
    int specialArray(vector<int>& a) {
        int n=a.size();
        vector<int> count(n+2,0);
        for(int i=0;i<n;i++)count[min(n,a[i])]++;
        for(int i=n;i>=0;i--){
            count[i]+=count[i+1];
            if(count[i]==i)return i;
        }
        return -1;
    }
};