class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),pro=1;
        vector<int> pre(n),suf(n),v(n);
        for(int i=0;i<n;i++){
            pro*=nums[i];
            pre[i]=pro;
        }
        pro=1;
        for(int i=n-1;i>=0;i--){
            pro*=nums[i];
            suf[i]=pro;
        }

        for(int i=0;i<n;i++){
            if(i==0)v[i]=suf[i+1];
            else if(i==n-1)v[i]=pre[i-1];
            else v[i]=pre[i-1]*suf[i+1];
        }

        return v;
    }
};