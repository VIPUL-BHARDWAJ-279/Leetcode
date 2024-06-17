class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0,right=sqrt(c);
        while(left<=right){
            long long num=left*left + right*right;
            if(num>c)right--;
            else if(num<c)left++;
            else return true;
        }
        return false;
    }
};