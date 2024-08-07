class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> v;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(i>0 && a[i]==a[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=a[i]+a[j]+a[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else {

                    v.push_back({a[i],a[j],a[k]});
                    j++;
                    k--;
                    while(j<k && a[j]==a[j-1])j++;
                    while(j<k && a[k]==a[k+1])k--;

                    
                }
            }

        }

        return v;
    }
};