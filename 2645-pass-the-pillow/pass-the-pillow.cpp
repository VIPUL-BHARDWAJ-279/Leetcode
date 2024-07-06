class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds=time/(n-1);
        int places=time%(n-1);

        if(places==0){
            if(rounds%2==0)return 1;
            else return n;
        }
        else{
            if(rounds%2==0)return 1+places;
            else return n-places;
        }
    }
};