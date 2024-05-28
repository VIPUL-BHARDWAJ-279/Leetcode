class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        int n=bill.size(),c5=0,c10=0;
        for(int i=0;i<n;i++){
            if(bill[i]==5)c5++;
            else if(bill[i]==10){
                c10++;
                if(c5==0)return false;
                else c5--;
            }
            else if(bill[i]==20){
                if(c10==0){
                    if(c5<3)return false;
                    else c5-=3;
                }
                else {
                    c10--;
                    if(c5==0)return false;
                    else c5--;
                }
            }
        }
        return true;
    }
};