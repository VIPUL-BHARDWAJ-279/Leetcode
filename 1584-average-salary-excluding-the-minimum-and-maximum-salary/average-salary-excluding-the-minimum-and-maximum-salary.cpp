class Solution {
public:
    double average(vector<int>& salary) {
        int maxi=INT_MIN,mini=INT_MAX,n=salary.size();
        double sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,salary[i]);
            mini=min(mini,salary[i]);
            sum+=salary[i];
        }
        sum-=(mini+maxi);
        double average=sum/(double)(n-2);
        return average;
    }
};