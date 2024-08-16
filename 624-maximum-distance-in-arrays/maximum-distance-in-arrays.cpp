class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int Maxi=INT_MIN/2,Mini=INT_MAX/2;
        int maxDiff=0;
        for(int i=0;i<arrays.size();i++){
            int n=arrays[i].size();
            int currMin=arrays[i][0],currMax=arrays[i][n-1];

            maxDiff=max({maxDiff,Maxi-currMin,currMax-Mini});

            Maxi=max(Maxi,currMax);
            Mini=min(Mini,currMin);
        }
        return maxDiff;
    }
};