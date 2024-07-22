class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int rowZero=0,colZero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    if(i==0)rowZero=1;
                    if(j==0)colZero=1;
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0)mat[i][j]=0;
            }
        }

        if(colZero)for(int i=0;i<n;i++)mat[i][0]=0;
        if(rowZero)for(int j=0;j<m;j++)mat[0][j]=0;


        

    }
};