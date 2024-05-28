class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        ios_base::sync_with_stdio(false),cin.tie(NULL);

        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=n-3;i>=0;i--){
            int x=a[i],y=a[i+1],z=a[i+2];
            if(x+y>z && y+z>x && x+z>y)return x+y+z;
        }
        return 0;
    }
};