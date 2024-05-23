class Solution {
public:
    string gameStatus(vector<vector<char>>& board){
        char winchar=' ';
        for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                if(board[i][0]=='X')return "A";
                else if(board[i][0]=='O')return "B";
                else return "Pending";
            }
        }
        for(int j=0;j<3;j++){
            if(board[0][j]==board[1][j] && board[1][j]==board[2][j]){
                if(board[0][j]=='X')return "A";
                else if(board[0][j]=='O')return "B";
                else return "Pending";
            }
        }
        if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
            if(board[1][1]=='X')return "A";
            else if(board[1][1]=='O')return "B";
            else return "Pending";
        }
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(board[i][j]==' ')return "Pending";
        return "Draw";
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3,vector<char>(3,' '));
        bool flag=true;
        for(auto move:moves){
            int x=move[0],y=move[1];
            board[x][y]=flag?'X':'O';
            flag=!flag;
        }
        return gameStatus(board);
    }
};