class Solution {
public:

    bool isPossibleFor_D_Days(vector<int> & a,int d,int m,int k){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=d)cnt++;
            else cnt=0;

            if(cnt==k)m--,cnt=0;
            if(m==0)return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        std::ios_base::sync_with_stdio(false);
        int s=0,e=0;
        for(int i=0;i<bloomDay.size();i++)e=max(e,bloomDay[i]);
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(isPossibleFor_D_Days(bloomDay,mid,m,k))ans=mid,e=mid-1;
            else s=mid+1;
        }
        return ans;
    }
};