class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);
        
        int n=customers.size(),s=0,unsat=0,maxUnsat=0,satisfied=0;

        for(int e=0;e<n;e++){
            satisfied+=customers[e]*(!grumpy[e]);

            int siz=e-s+1;
            if(siz<=minutes)unsat+=customers[e]*grumpy[e];
            else{
                unsat+=customers[e]*grumpy[e];
                unsat-=customers[s]*grumpy[s++];
            }
            if(unsat>maxUnsat)maxUnsat=unsat;
        }

        return satisfied+maxUnsat;
    }
};