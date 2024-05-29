class Solution {
public:
    int numSteps(string s) {
        int n=s.size(),steps=0,carry=0;
        for(int i=n-1;i>=1;i--){
            if(((s[i]-'0')+carry)%2==1)steps+=2,carry=1;
            else steps++;    
        }
        return steps+carry;   
    }
};