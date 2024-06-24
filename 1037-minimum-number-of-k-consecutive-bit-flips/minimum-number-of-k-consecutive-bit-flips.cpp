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



    // O(n) using map <---extra space
    // int minKBitFlips(vector<int>& a, int k){
    //     unordered_map<int,bool> mp;
    //     int n=a.size(),result=0,flipcnt=0;;

    //     for(int i=0;i<n;i++){
    //         if(mp[i-k]==true)flipcnt--;

    //         if(flipcnt%2==a[i]){
    //             if(i+k>n)return -1;
    //             flipcnt++;
    //             result++;
    //             mp[i]=true;
    //         }
    //     }
    //     return result;
    // }


    // BEST APPROACH: O(n) <---NO EXTRA SPACE

    int minKBitFlips(vector<int>& a, int k){
        int n=a.size(),result=0,flipcnt=0;;

        for(int i=0;i<n;i++){
            if(i>=k && a[i-k]==99)flipcnt--;

            if(flipcnt%2==a[i]){
                if(i+k>n)return -1;
                flipcnt++;
                result++;
                a[i]=99;
            }
        }
        return result;
    }
};