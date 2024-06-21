class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(),i=0;

        // for(int j=0;j<n;j++){
        //     if()
        // }




        int start,end,s=0,e=0;
        int unsat=0,maxUnsat=0,satisfied=0;
        while(e<customers.size()){
            int siz=e-s+1;
            if(siz<=minutes){
                unsat+=customers[e]*grumpy[e];
                e++;
            }
            else{
                unsat+=customers[e]*grumpy[e];
                e++;
                unsat-=customers[s]*grumpy[s];
                s++;   
            }
            if(unsat>maxUnsat){
                    start=s;
                    end=e-1;
                    maxUnsat=unsat;
                }
        }

        for(int i=0;i<customers.size();i++)satisfied+=customers[i]*(!grumpy[i]);
        return satisfied+maxUnsat;
    }
};