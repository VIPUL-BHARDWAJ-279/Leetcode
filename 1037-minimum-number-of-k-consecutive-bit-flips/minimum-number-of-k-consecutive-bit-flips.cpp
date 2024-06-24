class Solution {
public:

// BRUTE FORCE
    // int minKBitFlips(vector<int>& a, int k) {
    //     int flips=0,n=a.size();
    //     for(int i=0;i<n-k+1;i++){
    //         if(a[i]==0){
    //             for(int j=i;j<i+k;j++)a[j]=1-a[j];
    //             flips++;
    //         }
    //     }

    //     for(int i=n-k+1;i<n;i++)if(a[i]==0)return -1;
    //     return flips;
    // }


    int minKBitFlips(vector<int>& a, int k){
        unordered_map<int,int> mp;
        int n=a.size();
        int result=0,flipcnt=0;

        for(int i=0;i<n;i++){
            if(mp[i-k]>0)flipcnt--;
            if(a[i]==0){
                if(flipcnt%2==0){
                    if(i+k>n)return -1;
                    flipcnt++;
                    result++;
                    mp[i]++;
                }
            }
            else{
                if(flipcnt%2==1){
                    if(i+k>n)return -1;
                    flipcnt++;
                    result++;
                    mp[i]++;
                }
            }
        }

        return result;
    }
};