class Solution {
public:
    int findComplement(int n) {
        int ans=0,i=0;
        while(n){
            int bit=n%2;
            if(bit==0)ans+=pow(2,i);
            i++;
            n/=2;
        }
        return ans;
    }
};