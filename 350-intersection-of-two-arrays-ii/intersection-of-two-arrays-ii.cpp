class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));

        int x1=0,x2=0;
        vector<int> ans;
        int n1=nums1.size(),n2=nums2.size();

        while(x1<n1 && x2<n2){
            if(nums1[x1]<nums2[x2])x1++;
            else if(nums1[x1]>nums2[x2])x2++;
            else {
                ans.push_back(nums1[x1]);
                x1++;
                x2++;
            }
        }
        return ans;
    }
};