class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0,i=0,n=mat.size();
        while(i<n){
            sum+=mat[i][i];
            if(i!=n-1-i)sum+=mat[i][n-1-i];
            i++;
        }
        
        return sum;
    }
};