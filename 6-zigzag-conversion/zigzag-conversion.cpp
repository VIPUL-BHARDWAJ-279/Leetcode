class Solution {
public:
    string convert(string s, int rows) {
        if(rows==1)return s;
        int n=s.size();
        vector<vector<char>> adj(rows);
        bool uptodown=true;
        adj[0].push_back(s[0]);
        int k=1;
        while(k<n){
            if(uptodown==true){
                for(int i=1;i<rows;i++){
                    adj[i].push_back(s[k]);
                    k++;
                    if(k>=n)break;
                }
                uptodown=false;
            }
            else{
                for(int i=rows-2;i>=0;i--){
                    adj[i].push_back(s[k]);
                    k++;
                    if(k>=n)break;
                }
                uptodown=true;
            }
        }
        string ans="";
        for(int i=0;i<rows;i++){
            for(int j=0;j<adj[i].size();j++)ans+=adj[i][j];
        }
        return ans;
        
    }
};