class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n=a.size();
        int xori=0;
        for(int i=0;i<n;i++){
            xori^=i;
            xori^=a[i];
        }
        return xori^n;
    }
};