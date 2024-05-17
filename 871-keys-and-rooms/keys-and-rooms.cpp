class Solution {
public:
    void dfs(int rootNode, vector<vector<int>>& rooms, vector<bool> & vis){
        vis[rootNode]=true;
        for(auto it:rooms[rootNode])if(!vis[it])dfs(it,rooms,vis);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(0,rooms,vis);
        for(auto x:vis)if(x==false)return false;
        return true;
    }
};