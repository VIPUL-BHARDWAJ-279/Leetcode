class Solution {
public:
    bool isNStraightHand(vector<int>& a, int GROUPSIZE) {
        if(GROUPSIZE==1)return true;
        map<int,int> mp;
        for(int i=0;i<a.size();i++)mp[a[i]]++;
        int count=0;
        for(auto x:mp){
            if(mp[x.first]!=0){
                int val=mp[x.first];
                int i=1;
                while(i<GROUPSIZE){
                    if(mp.find(x.first+i)!=mp.end() && mp[x.first+i]>=mp[x.first+i-1])mp[x.first+i]-=val;
                    else return false;
                    i++;
                }
                mp[x.first]-=val;
                count+=val;
            }

        }
        if(count*GROUPSIZE==a.size())return true;
        return false;
        
    }
};