#include<bits/stdc++.h>
class Solution {
public:

    // void nextPermutation(vector<int>& a) {
    //     int n=a.size();
    //     int indx=-1; // indx=dipPoint
    //     for(int i=n-2;i>=0;i--){
    //         if(a[i]<a[i+1]){
    //             indx=i;
    //             break;
    //         }
    //     }
    //     if(indx==-1) return reverse(a.begin(),a.end());
    //     for(int i=n-1;i>indx;i--){//swap dipPoint element with the element which is smallest among the elements greater than dipPoint element
    //         if(a[i]>a[indx]){
    //             swap(a[i],a[indx]);
    //             break;
    //         }
    //     }
    //     reverse(a.begin()+indx+1,a.end());//sort the vector after dipPoint index
    //     //here reverse == sort as the elements after dipPoint are already sorted in descending order

    // }




    void nextPermutation(vector<int>& a) {
        int n=a.size(),dipPoint=-1; // next permutation banane ke liye koi ek number badhana hoga (uske aage aane wale numbers me se kisi se swap karke) aur uske aage wale numbers ko sort karna hoga. DipPoint aisa first number leta hai backside se taaki aage se longest matching ho sake.
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                dipPoint=i;
                break;
            }
        }
        if(dipPoint==-1)return sort(a.begin(),a.end());

        sort(a.begin()+dipPoint+1,a.end());
        for(int i=dipPoint+1;i<n;i++){
            if(a[i]>a[dipPoint]){
                swap(a[i],a[dipPoint]);
                break;
            }
        }

    }
};