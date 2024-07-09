class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitTime=0;
        int n=customers.size(), currentTime=0;
        for(auto & x:customers){
            int arrivalTime=x[0],cookTime=x[1];
            if(arrivalTime>currentTime)currentTime=arrivalTime;
            int waitTime=currentTime + cookTime - arrivalTime;
            totalWaitTime+=waitTime;

            currentTime+=cookTime;
        }

        return totalWaitTime/n;

    }
};