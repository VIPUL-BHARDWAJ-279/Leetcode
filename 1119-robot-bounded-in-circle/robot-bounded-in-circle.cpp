class Solution {
public:
    bool isRobotBounded(string instructions) {

        vector<vector<int>> directions={{0,1},{-1,0},{0,-1},{1,0}};
        int x=0,y=0,currentDir=0, siz=instructions.size();

        instructions+=instructions;
        instructions+=instructions;
        instructions+=instructions;
        
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='G'){
                x+=directions[currentDir][0];
                y+=directions[currentDir][1];
            }
            else if(instructions[i]=='L'){
                currentDir=(currentDir+1)%4;
            }
            else currentDir=(4+currentDir-1)%4;

            if(x==0 && y==0 && i%siz==siz-1)return true;
        }
        return false;
    }
};