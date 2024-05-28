class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);
        
        int n=bill.size(),c5=0,c10=0;
        for(int i=0;i<n;i++){
            if(bill[i]==5)c5++;
            else if(bill[i]==10){
                c10++;
                if(c5)c5--;
                else return false;
            }
            else if(bill[i]==20){
                if(c10 && c5)c10--,c5--;
                else if( c10==0 && c5>=3)c5-=3;
                else return false;
            }
        }
        return true;
    }
};