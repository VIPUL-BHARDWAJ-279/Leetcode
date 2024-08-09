class Solution {
public:
    bool isMagicSquare(int x, int y, vector<vector<int>>& grid){
        unordered_set<int> seti;
        for(int i=x;i<x+3;i++){
            int sum=0;
            for(int j=y;j<y+3;j++){
                sum+=grid[i][j];
                if(grid[i][j]<1 || grid[i][j]>9)return false;
                seti.insert(grid[i][j]);
            }
            if(sum!=15)return false;
        }

        if(seti.size()!=9)return false;

        for(int j=y;j<y+3;j++){
            int sum=0;
            for(int i=x;i<x+3;i++)sum+=grid[i][j];
            if(sum!=15)return false;
        }

        if(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]!=15  ||  grid[x+2][y]+grid[x+1][y+1]+grid[x][y+2]!=15)return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m<3 || n<3)return 0;
        int count=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(isMagicSquare(i,j,grid))count++;
            }
        }

        return count;
    }
};