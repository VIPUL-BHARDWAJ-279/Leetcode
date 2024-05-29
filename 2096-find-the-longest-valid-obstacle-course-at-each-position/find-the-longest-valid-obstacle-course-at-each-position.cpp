class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n=obs.size();
        vector<int> LIS,result(n); // LIS[index]=x implies length of LIS ending at x is index+1

        for(int i=0;i<n;i++){
            int index=upper_bound(LIS.begin(),LIS.end(),obs[i])-LIS.begin();

            if(index==LIS.size()) LIS.push_back(obs[i]);
            else LIS[index]=min(LIS[index],obs[i]);

            result[i]=index+1;
        }
        return result;
    }
};