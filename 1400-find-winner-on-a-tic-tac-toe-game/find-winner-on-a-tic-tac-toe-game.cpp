class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n=3;
        int rows[3]={0},cols[3]={0};
        int mainDiag=0,antiDiag=0;

        int player=1;
        for(int i=0;i<moves.size();i++){
            int r=moves[i][0],c=moves[i][1];
            rows[r]+=player;
            cols[c]+=player;
            if(r==c)mainDiag+=player;
            if(r+c==n-1)antiDiag+=player;
            if(abs(rows[r])==n || abs(cols[c])==n || abs(mainDiag)==n || abs(antiDiag)==n)return player==1?"A":"B";
            player=-player;
        }
        return moves.size()==9?"Draw":"Pending";
    }
};