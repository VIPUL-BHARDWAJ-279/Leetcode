class Solution {
public:
int cnt=0,ans=0;
    int minimumDeletions(string s) {
        for(auto ch:s){
            if(ch=='b')cnt++;
            else{
                if(cnt>0){
                    ans++;
                    cnt--;
                }
            }
        }
        return ans;
    }
};