class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),cnt9=0;
        for(int i=0;i<n;i++)if(digits[i]==9)cnt9++;
        if(cnt9==digits.size()){
            for(int i=0;i<n;i++)digits[i]=0;
            digits.push_back(0);
            digits[0]=1;
        }
        else{
            int carry=1;
            for(int i=n-1;i>=0;i--){
                int sum=digits[i]+carry;
                digits[i]=sum%10;
                carry=sum/10;
            }
        }
        return digits;   
    }
};