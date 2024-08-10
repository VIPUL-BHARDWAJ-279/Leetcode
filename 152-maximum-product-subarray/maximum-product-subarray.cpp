class Solution {
public:
    int maxProduct(vector<int>& a) {
        long long proUptoFirstNegative=1,pro=1,ans=INT_MIN,n=a.size();

        for(int i=0;i<n;i++){
            pro*=a[i];

            if(pro<0)ans=max(ans,pro*proUptoFirstNegative);
            else ans=max(ans,pro);

            if(a[i]<0 && proUptoFirstNegative==1){
                proUptoFirstNegative=pro;
                pro=1;
            }

            if(a[i]==0){
                proUptoFirstNegative=1;
                pro=1;  
            }
        }

        return ans;

    }
};