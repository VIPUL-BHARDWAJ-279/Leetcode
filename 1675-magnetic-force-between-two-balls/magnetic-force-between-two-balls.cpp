class Solution {
public:
    bool isAnswer(int d,int m, vector<int> & position) {
        int cnt=1,start=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-start>=d){
                start=position[i];
                cnt++;
            }
            if(cnt==m)return true;
        }
        return false;
    }


    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
        int n=position.size();
        int s=0,e=position[n-1],ans;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(isAnswer(mid,m,position))ans=mid,s=mid+1;// if this gap is sufficient enough try widening the gap
            else e=mid-1;
        }
        return ans;// reduce the gap size 
    }
};