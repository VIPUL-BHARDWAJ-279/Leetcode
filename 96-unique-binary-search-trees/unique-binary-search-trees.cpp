class Solution {
public:
    map<pair<int,int>,int> mp;
    int solve(int start, int end){
        if(start>end)return 0;
        if(start==end)return mp[{start,end}]=1;

        if(mp.find({start,end})!=mp.end())return mp[{start,end}];
        int ans=0;
        for(int i=start;i<=end;i++){
            int left_BSTs=solve(start,i-1);
            int right_BSTs=solve(i+1,end);

            if(left_BSTs==0 || right_BSTs==0)ans+=max(left_BSTs,right_BSTs);
            else ans+=left_BSTs * right_BSTs;
        }
        return mp[{start,end}] = ans;
    }
    int numTrees(int n) {
        return solve(1,n);
    }
};







