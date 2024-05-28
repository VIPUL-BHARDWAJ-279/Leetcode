class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);

        int n=a.size();
        int x1=a[0][0],y1=a[0][1],x2=a[1][0],y2=a[1][1];
        for(int i=2;i<n;i++){
            int x=a[i][0],y=a[i][1];
            if((x-x1)*(y2-y1) != (y-y1)*(x2-x1))return false;
        }
        return true;
    }
};